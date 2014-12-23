#include "document.h"

#include "pool.h"
#include "escape.h"

#include <string.h>
#include <assert.h>


#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)



// GENERAL INITIALIZATION
// ----------------------
//
// Define hoedown_document, and export the constructor, destructor
// and general utilities and types used across the code.


#define LINK_REFS_TABLE_SIZE 16

struct link_ref {
  unsigned int id;
  hoedown_buffer *dest;
  hoedown_buffer *title;
  int has_title;

  struct link_ref *next;
};

static void *new_link_ref(void *opaque) {
  struct link_ref *ref = malloc(sizeof(struct link_ref));
  ref->dest = hoedown_buffer_new(16);
  ref->title = hoedown_buffer_new(16);
  return ref;
}

static void free_link_ref(void *item, void *opaque) {
  struct link_ref *ref = item;
  hoedown_buffer_free(ref->title);
  hoedown_buffer_free(ref->dest);
}


typedef size_t (*char_trigger)(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size);
typedef int (*delimiter_check)(hoedown_document *doc, const uint8_t *data, size_t parsed, size_t start, size_t size, void *opaque);

static inline void restrict_features(const hoedown_renderer *rndr, hoedown_features *ft);
static inline void set_active_chars(char_trigger *active_chars, hoedown_features ft);

enum parsing_mode {
  // Skip all blocks without parsing their inline content,
  // but still parse block content.
  DUMB_PARSING,

  // In this mode, blocks are parsed, but not rendered.
  // The content of a block is not parsed unless it's also block content,
  // or it's the content of a marker.
  //
  // This mode is used once when rendering, to parse the markers of a document.
  // Markers themselves aren't rendered, but their content is parsed, rendered
  // and hashed for later.
  MARKER_PARSING,

  // This is the normal mode of operation. Everything is parsed and renderer,
  // except markers, which are simply skipped.
  //
  // After parsing with MARKER_PARSING mode, this mode is used to parse
  // and render the document.
  NORMAL_PARSING,
};

struct hoedown_document {
  // user-specified
  hoedown_renderer rndr;
  hoedown_features ft;
  size_t max_nesting;

  // for renderer use
  hoedown_renderer_data data;

  // for general operation
  size_t current_nesting;
  size_t is_tight;
  enum parsing_mode mode;
  int inside_link;
  hoedown_buffer *text;

  // for marker parsing
  hoedown_pool marker_link_refs;
  struct link_ref *link_refs_table [LINK_REFS_TABLE_SIZE];

  // for normal parsing
  hoedown_pool buffers_block;
  hoedown_pool buffers_inline;
  char_trigger active_chars[256];
};

hoedown_document *hoedown_document_new(
  hoedown_renderer *renderer,
  hoedown_features features,
  size_t max_nesting
) {
  restrict_features(renderer, &features);

  hoedown_document *doc = hoedown_malloc(sizeof(hoedown_document));

  memcpy(&doc->rndr, renderer, sizeof(hoedown_renderer));
  doc->ft = features;
  doc->max_nesting = max_nesting;

  doc->data.doc = (hoedown_internal *)doc;
  doc->data.opaque = renderer->opaque;

  doc->current_nesting = 0;
  doc->inside_link = 0;
  doc->is_tight = 0;
  doc->text = hoedown_buffer_new(64);

  //FIXME: this needs limiting
  hoedown_pool_init(&doc->marker_link_refs, 4, new_link_ref, free_link_ref, NULL);

  hoedown_buffer_pool_init(&doc->buffers_block, 4, 16);
  hoedown_buffer_pool_init(&doc->buffers_inline, 8, 16);
  set_active_chars(doc->active_chars, features);

  return doc;
}

void hoedown_document_free(hoedown_document *doc) {
  if (!doc) return;

  hoedown_buffer_free(doc->text);

  hoedown_pool_uninit(&doc->marker_link_refs);

  hoedown_pool_uninit(&doc->buffers_block);
  hoedown_pool_uninit(&doc->buffers_inline);

  free(doc);
}



// LOW LEVEL PARSING UTILITIES
// ---------------------------
//
// Very simple methods that help in parsing. We could use isalpha, isspace,
// isalnum and friends, but they're locale dependent. We don't like that.
//
// **Important:** the code in the section below for parsing HTML depends on
// these functions. If any of these functions is modified, the code at the
// section below should call a (preserved) copy instead.


// Checks if the char is an ASCII digit.
static inline int is_digit_ascii(uint8_t ch) {
  return ch >= '0' && ch <= '9';
}

// Checks if the char is an uppercase ASCII letter.
static inline int is_upper_ascii(uint8_t ch) {
  return ch >= 'A' && ch <= 'Z';
}

// Checks if the char is an lowercase ASCII letter.
static inline int is_lower_ascii(uint8_t ch) {
  return ch >= 'a' && ch <= 'z';
}

// Checks if the char is an alphanumeric ASCII character.
static inline int is_alnum_ascii(uint8_t ch) {
  return is_lower_ascii(ch) || is_upper_ascii(ch) || is_digit_ascii(ch);
}

// Checks if the char is an ASCII punctuation character.
static inline int is_punct_ascii(uint8_t ch) {
  static const char punctuation_chars [256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  return punctuation_chars[ch];
}

// Checks if the char is a valid space character.
// Tabs and carriage returns are stripped during preprocessing.
// Form feeds aren't treated as spacing (except for HTML).
static inline int is_space(uint8_t ch) {
  return ch == 0x20 // space
      // ch == 0x09 // tab
      || ch == 0x0a // linefeed
      // ch == 0x0c // form feed
      // ch == 0x0d // carriage return
      ;
}

// HTML-specific version of is_space
static inline int html_is_space(uint8_t ch) {
  return ch == 0x20 // space
      // ch == 0x09 // tab
      || ch == 0x0a // linefeed
      || ch == 0x0c // form feed
      // ch == 0x0d // carriage return
      ;
}


// Checks if the character at a certain position in the input
// is backslash escaped or not.
static inline int is_escaped(const uint8_t *data, size_t position) {
  size_t start = position;
  while (start > 0 && data[start-1] == '\\') start--;
  return (position - start) % 2;
}

// Replaces all uppercase ASCII letters in the string
// with their lowercase counterparts.
static inline void to_lower_ascii(uint8_t *data, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (is_upper_ascii(data[i]))
      data[i] += 0x20;
  }
}

// Checks if the data passed is all spacing.
static inline int is_empty(const uint8_t *data, size_t size) {
  size_t i = 0;
  while (i < size && is_space(data[i])) i++;
  return i >= size;
}

// Returns position of the next line (or end of input, wathever happens before)
// but only if the current line is all spacing. Otherwise, zero is returned.
static inline size_t next_line_empty(const uint8_t *data, size_t size) {
  size_t i = 0;
  
  while (i < size && data[i] == ' ') i++;
  
  if (unlikely(i >= size)) return i;
  if (data[i] == '\n') return i + 1;
  return 0;
}

// Replaces all occurences of consecutive spacing characters with a single
// space character.
static inline void collapse_spacing(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0, mark = 0;
  while (1) {
    while (i < size && !is_space(data[i])) i++;
    
    // Optimization: it's a single space, we don't need to replace anything
    if (likely(i+1 < size && data[i] == ' ' && !is_space(data[i+1]))) {
      i += 2;
      continue;
    }

    // Optimization: there's nothing to replace
    if (mark == 0 && i >= size) {
      hoedown_buffer_put(ob, data, size);
      return;
    }

    hoedown_buffer_put(ob, data + mark, i - mark);
    if (i >= size) break;

    hoedown_buffer_putc(ob, ' ');
    i++;

    while (i < size && is_space(data[i])) i++;
    mark = i;
  }
}

// Unescapes ASCII punctuation characters escaped with a backslash.
static inline void unescape_backslash(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0, mark = 0;
  while (1) {
    while (i < size && data[i] != '\\') i++;

    // Optimization: there's nothing to unescape
    if (mark == 0 && i >= size) {
      hoedown_buffer_put(ob, data, size);
      return;
    }

    if (i+1 < size && !is_punct_ascii(data[i+1])) {
      i += 2;
      continue;
    }

    hoedown_buffer_put(ob, data + mark, i - mark);
    if (i >= size) break;

    i++;
    mark = i;
    i++;
  }
}

// Utility method to unescape both backslashes and HTML entities.
static inline void unescape_both(hoedown_document *doc, hoedown_buffer *ob, const uint8_t *data, size_t size) {
  hoedown_buffer *intermediate = hoedown_pool_get(&doc->buffers_inline);
  intermediate->size = 0;

  unescape_backslash(intermediate, data, size);
  hoedown_unescape_html(ob, intermediate->data, intermediate->size);

  hoedown_pool_pop(&doc->buffers_inline, intermediate);
}



// OTHER UTILITIES
// ---------------
//
// Miscellaneous logic used when parsing.

static inline unsigned int hash_string(const uint8_t *data, size_t size) {
  unsigned int hash = 0;

  for (size_t i = 0; i < size; i++) {
    uint8_t c = data[i];
    if (c >= 'A' && c <= 'Z') c += 0x20;
    hash = c + (hash << 6) + (hash << 16) - hash;
  }

  return hash;
}

static inline void add_link_ref(hoedown_document *doc, struct link_ref *ref) {
  struct link_ref **slot = &doc->link_refs_table[ref->id % LINK_REFS_TABLE_SIZE];
  ref->next = *slot;
  *slot = ref;
}

static inline struct link_ref *find_link_ref(hoedown_document *doc, unsigned int id) {
  struct link_ref *ref = doc->link_refs_table[id % LINK_REFS_TABLE_SIZE];

  while (ref) {
    if (ref->id == id) return ref;
    ref = ref->next;
  }

  return NULL;
}



// HTML PARSING
// ------------
//
// This code is an adapted version of Lanli's HTML parsing routines.
// This only returns the end of a tag, without saving any data, since we
// don't need to interpret a tag, only skip it. The name of the tag can
// optionally be saved, since we need it to check if a tag is a block.


// Checks if the char can be part of an attribute name.
// NOTE: CommonMark is stricter than HTML5.
static inline int html_is_attr_name_char(uint8_t ch) {
  // If we wanted to be 100% HTML-compliant, we should allow
  // more characters to be part of attribute names.
  return is_alnum_ascii(ch) || ch == '-' || ch == '_' || ch == ':' || ch == '.';
}

// Checks if the char is sensitive and can't be found inside
// unquoted attribute values, according to the HTML5 spec.
static inline int html_is_attr_sensitive(uint8_t ch) {
  return ch == '<' || ch == '>' || ch == '='
      || ch == '"' || ch == '`' || ch == '\'';
}

// Parse an attribute value if there's one, according to the HTML5 spec.
// Sets parsed value to the buffer passed.
// Returns 0 if there's no value, size of the value otherwise.
static size_t html_parse_attribute_value(const uint8_t *data, size_t size) {
  size_t i = 0, mark;
  while (i < size && html_is_space(data[i])) i++;

  if (!(i < size)) return 0;
  uint8_t delimiter = data[i];

  if (delimiter == '\'' || delimiter == '"') {
    i++;
    // Quoted attribute
    while (i < size && data[i] != delimiter) i++;
    if (likely(i < size)) return i + 1;
    return 0;
  }

  // Unquoted attribute
  mark = i;
  while (i < size && !html_is_space(data[i]) && !html_is_attr_sensitive(data[i])) i++;
  if (unlikely(mark == i)) return 0;

  return i;
}

// Parse an attribute if there's one, according to the HTML5 spec.
// Returns 0 if there's no valid attribute, size of the attribute otherwise.
static size_t html_parse_attribute(const uint8_t *data, size_t size) {
  size_t i = 0, mark;

  // There must be at least one space character as separation
  mark = i;
  while (i < size && html_is_space(data[i])) i++;
  if (mark == i) return 0;

  // Collect attribute name
  mark = i;
  while (i < size && html_is_attr_name_char(data[i])) i++;
  if (mark == i || data[mark] == '.' || data[mark] == '-') return 0;

  // Collect attribute value, if there is
  mark = i;
  while (i < size && html_is_space(data[i])) i++;
  if (i < size && data[i] == '=') {
    i++;
    // Attribute with value
    mark = i;
    i += html_parse_attribute_value(data + i, size - i);
    if (mark == i) return 0;
    return i;
  } else {
    // Attribute without value
    return mark;
  }

  // If we wanted to be 100% HTML-compliant, we should enforce
  // an unquoted attribute to have at least one space character
  // next, if it's followed by a slash.
}

// Parse a start tag if there's one, according to CommonMark.
// This method assumes that data[0] == '<', so check that before calling it.
// Returns 0 if there's no start tag, size of the tag otherwise.
// NOTE: CommonMark requires a tag name to start with a letter
static size_t html_parse_start_tag(hoedown_buffer *name, const uint8_t *data, size_t size) {
  size_t i = 1, mark;

  // Collect the tag name
  mark = i;

  if (i < size && (is_lower_ascii(data[i]) || is_upper_ascii(data[i]))) i++;
  else return 0;

  while (i < size && is_alnum_ascii(data[i])) i++;

  if (mark == i) return 0;
  if (name) hoedown_buffer_set(name, data + mark, i - mark);

  // Collect the attributes
  while (1) {
    mark = i;
    i += html_parse_attribute(data + i, size - i);
    if (mark == i) break;
  }

  // Collect optional spacing
  while (i < size && html_is_space(data[i])) i++;

  // Optional slash
  if (i < size && data[i] == '/') i++;

  // Ending angle bracket
  if (i < size && data[i] == '>')
    return i + 1;
  return 0;
}

// Parse an end tag if there's one, according to the HTML5 spec.
// This method assumes that data[0] == '<', so check that before calling it.
// Returns 0 if there's no end tag, size of the tag otherwise.
static size_t html_parse_end_tag(hoedown_buffer *name, const uint8_t *data, size_t size) {
  size_t i = 1, mark;

  // Slash
  if (i < size && data[i] == '/') i++;
  else return 0;

  // Collect tag name
  mark = i;
  while (i < size && is_alnum_ascii(data[i])) i++;
  if (mark == i) return 0;
  if (name) hoedown_buffer_set(name, data + mark, i - mark);

  // Collect optional spacing
  while (i < size && html_is_space(data[i])) i++;

  // Ending angle bracket
  if (i < size && data[i] == '>')
    return i + 1;
  return 0;
}

// Parse a comment if there's one, according to the HTML5 spec.
// This method assumes that data[0] == '<', so check that before calling it.
// Returns 0 if there's no comment, size of the comment otherwise.
static size_t html_parse_comment(const uint8_t *data, size_t size) {
  size_t i = 1;
  if (size < 7) return 0;

  // Ensure starting sequence
  if (data[1] == '!' && data[2] == '-' && data[3] == '-') i = 4;
  else return 0;

  // Validate start of comment content
  if (i+2 >= size) return 0;
  if (data[i] == '>') return 0;
  if (data[i] == '-' && data[i+1] == '>') return 0;

  // Collect content
  while (i+2 < size && !(data[i] == '-' && data[i+1] == '-')) i++;
  if (i+2 >= size) return 0;

  // Verify end of comment
  if (data[i+2] != '>') return 0;
  return i + 3;
}



// ACTUAL PARSING
// --------------
//
// Logic to parse various Markdown constructs. By convention, inline
// constructs are declared first, then block constructs.
//
// There are two types of methods. Tests are prefixed with `text_`, and they
// doesn't parse the construct, just look quickly for a *possibility*
// of the construct being present.
//
// Then there are the actual parsing routines, prefixed with `parse_`. They
// follow very specific guidelines, which are there to prevent bugs or
// unsafe operations, and guarantee readability.
//
// Block parsing functions should never return a position that falls in the
// middle of a line. Block parsing functions should always be called at the
// start of a non-empty line.
//
// Parsing functions must ALWAYS be called ONLY if
// the associated callbacks are defined in the renderer, that is, if the
// feature flag is set.

// These are defined later
static size_t parse_inline(hoedown_document *doc, void *target, const uint8_t *data, size_t size, uint8_t delimiter, delimiter_check check, void *opaque);
static size_t parse_any_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t i, size_t size, size_t lazy_size, hoedown_features lazy_ft);
static size_t parse_block(hoedown_document *doc, void *target, const uint8_t *data, size_t size, size_t lazy_size, hoedown_features lazy_ft);


// COMMON PARSING
// Syntax shared between block and inline constructs

static inline size_t parse_link_destination(hoedown_document *doc, hoedown_buffer *dest, const uint8_t *data, size_t size) {
  size_t i = 0, mark;
  if (i >= size) return 0;

  if (data[i] == '<') {
    i++;
    mark = i;

    // Find ending delimiter
    while (1) {
      while (i < size && data[i] != '>' && data[i] != '<' && data[i] != '\n') i++;
      if (i >= size) return 0;

      if ((data[i] == '>' || data[i] == '<') && is_escaped(data, i)) {
        i++;
        continue;
      }

      if (data[i] == '>') break;
      return 0;
    }

    if (dest) {
      dest->size = 0;
      unescape_both(doc, dest, data + mark, i - mark);
    }
    return i + 1;
  } else {
    mark = i;

    // Find ending delimiter
    int in_parenthesis = 0;
    while (1) {
      while (i < size && data[i] > ' ' && data[i] != '(' && data[i] != ')') i++;
      if (i >= size) break;

      if (data[i] == '(' || data[i] == ')') {
        if (is_escaped(data, i)) {
          i++;
          continue;
        }
        if ((data[i] == ')') == in_parenthesis) {
          i++;
          in_parenthesis = !in_parenthesis;
          continue;
        }
      }

      break;
    }

    if (i == mark || in_parenthesis) return 0;
    if (dest) {
      dest->size = 0;
      unescape_both(doc, dest, data + mark, i - mark);
    }
    return i;
  }
}

static inline size_t parse_link_title(hoedown_document *doc, hoedown_buffer *title, const uint8_t *data, size_t size) {
  size_t i = 0, mark;

  // Spacing, up to one newline
  mark = i;
  while (i < size && data[i] == ' ') i++;
  if (i < size && data[i] == '\n') {
    i++;
    while (i < size && data[i] == ' ') i++;
  }
  if (mark == i) return 0;

  // Starting delimiter
  uint8_t delimiter = data[i];
  if (delimiter == '\'' || delimiter == '"' || delimiter == '(') i++;
  else return 0;

  if (delimiter == '(') delimiter = ')';

  // Find ending delimiter
  mark = i;
  while (1) {
    while (i < size && data[i] != delimiter) i++;
    if (i >= size) return 0;

    if (is_escaped(data, i)) {
      i++;
      continue;
    }

    break;
  }

  if (title) {
    title->size = 0;
    unescape_both(doc, title, data + mark, i - mark);
  }
  return i + 1;
}

static inline size_t parse_link_spec(hoedown_document *doc, struct link_ref *spec, const uint8_t *data, size_t size) {
  size_t i = 0, mark;

  // Link destination
  mark = i;
  i += parse_link_destination(doc, spec ? spec->dest : NULL, data + i, size - i);
  if (mark == i) return 0;

  // Optional link title
  mark = i;
  i += parse_link_title(doc, spec ? spec->title : NULL, data + i, size - i);
  if (spec) spec->has_title = (mark < i);

  return i;
}


// INLINE PARSING

// This is the fallback parsing function for inline parsing.
static inline void parse_string(hoedown_document *doc, void *target, const uint8_t *data, size_t size) {
  if (size == 0) return;
  hoedown_buffer text = {(uint8_t *)data, size, 0, 0, NULL, NULL};
  doc->rndr.string(target, &text, &doc->data);
}

// Assumes data[0] == '`'
static inline size_t parse_code_span(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  if (start > parsed && data[start-1] == '`') return 0;

  size_t i = start + 1, content_start, mark;
  size_t width;

  // Opening backticks
  mark = i;
  while (i < size && data[i] == '`') i++;
  width = i - mark;

  // Skip leading spacing
  while (i < size && is_space(data[i])) i++;

  // Consume content
  content_start = i;
  while (1) {
    while (i < size && data[i] != '`') i++;

    if (i < size) i++;
    else return 0;

    mark = i;
    while (i < size && data[i] == '`') i++;
    if (i - mark == width) break;
  }
  i = mark + width;
  mark--;

  // Rewind trailing spaces on content
  while (mark > content_start && is_space(data[mark-1])) mark--;

  // Render!
  parse_string(doc, target, data + parsed, start - parsed);

  hoedown_buffer *code = hoedown_pool_get(&doc->buffers_block);
  code->size = 0;
  collapse_spacing(code, data + content_start, mark - content_start);

  doc->rndr.code_span(target, code, &doc->data);
  hoedown_pool_pop(&doc->buffers_block, code);
  return i;
}

// data[0] is assumed to be '<'
static inline size_t parse_uri_autolink(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start + 1, mark;

  // Collect scheme
  mark = i;
  while (i < size && data[i] != ':') i++;
  if (i < size && hoedown_find_autolink_scheme((const char *)data + mark, i - mark)) i++;
  else return 0;

  // Rest of URL
  while (i < size && data[i] > ' ' && data[i] != '>' && data[i] != '<') i++;
  if (i >= size || data[i] != '>') return 0;

  // Render!
  parse_string(doc, target, data + parsed, start - parsed);

  hoedown_buffer url = {(uint8_t *)data + mark, i - mark, 0, 0, NULL, NULL};
  doc->rndr.uri_autolink(target, &url, &doc->data);
  return i + 1;
}

// data[0] is assumed to be '<'
static inline size_t parse_email_autolink(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start + 1, mark;//TODO

  // Collect username
  
  return i + 1;
}

// Parse the syntax for an inline link.
// If the syntax is invalid, zero will be returned.
// If it's valid, `target` will be populated with the parsed data.
static inline size_t parse_link_target_inline(hoedown_document *doc, struct link_ref *spec, const uint8_t *data, size_t size) {
  size_t i = 0, mark;

  // Parenthesis
  if (i < size && data[i] == '(') i++;
  else return 0;

  // Optional spacing
  while (i < size && is_space(data[i])) i++;

  // Optional spec
  mark = i;
  i += parse_link_spec(doc, spec, data + i, size - i);

  if (mark == i) {
    // If there's no specification, empty destination and no title
    spec->dest->size = 0;
    spec->has_title = 0;
  }

  // Optional spacing
  while (i < size && is_space(data[i])) i++;

  // Parenthesis
  if (i < size && data[i] == ')') i++;
  else return 0;

  return i;
}

// Parses the syntax for a full / collapsed reference link.
// If the syntax is invalid, zero will be returned.
// If the syntax is valid, `target` will be set to the match
// (or NULL if there's no match).
static inline size_t parse_link_target_reference(hoedown_document *doc, struct link_ref **spec, const uint8_t *data, size_t size, const hoedown_buffer *content) {
  size_t i = 0, mark;

  // Optional spacing
  while (i < size && is_space(data[i])) i++;

  // Bracket
  if (i < size && data[i] == '[') i++;
  else return 0;

  // Content
  mark = i;
  while (i < size && data[i] != ']') i++;
  if (i >= size) return 0;

  // Lookup the reference
  hoedown_buffer *label = hoedown_pool_get(&doc->buffers_inline);
  label->size = 0;

  if (mark < i)
    collapse_spacing(label, data + mark, i - mark);
  else
    collapse_spacing(label, content->data, content->size);

  *spec = find_link_ref(doc, hash_string(label->data, label->size));
  hoedown_pool_pop(&doc->buffers_inline, label);
  return i + 1;
}

static inline size_t parse_link_target(hoedown_document *doc, struct link_ref **spec, const uint8_t *data, size_t size, const hoedown_buffer *content) {
  size_t result;

  // Try to parse inline link

  // DANGER: we're doing something unsafe, taking a link ref and
  // revoking it, but still using it and passing it upwards. As long as it's
  // only called by `parse_link`...
  *spec = hoedown_pool_get(&doc->marker_link_refs);
  result = parse_link_target_inline(doc, *spec, data, size);
  hoedown_pool_pop(&doc->marker_link_refs, *spec);

  if (result) return result;

  // Try to parse full / collapsed reference link

  if ((result = parse_link_target_reference(doc, spec, data, size, content)))
    return result;

  // Nothing? Then try to match this as a shortcut link

  hoedown_buffer *label = hoedown_pool_get(&doc->buffers_inline);
  label->size = 0;
  collapse_spacing(label, content->data, content->size);
  *spec = find_link_ref(doc, hash_string(label->data, label->size));
  hoedown_pool_pop(&doc->buffers_inline, label);
  return 0;
}

// data[0] is assumed to be '['
static inline size_t parse_link(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start + 1, mark, label_start, label_end;
  int current_inside_link = doc->inside_link;
  int is_image = 0;

  // Is it an image?
  if (start > parsed && data[start-1] == '!' && doc->ft & HOEDOWN_FT_LINK_IMAGE) {
    is_image = 1;
    start--;
  }

  // Link label
  void *content = doc->rndr.object_get(1, &doc->data);
  label_start = i;

  doc->inside_link = 1;
  i += parse_inline(doc, content, data + i, size - i, ']', NULL, NULL);
  doc->inside_link = current_inside_link;

  if (i >= size) {
    // delimiter not found
    doc->rndr.object_pop(content, 1, &doc->data);
    return 0;
  }

  label_end = i;
  i++;

  // Try to parse some type of link target
  struct link_ref *spec = NULL;
  hoedown_buffer content_text = {(uint8_t *)data + label_start, label_end - label_start, 0, 0, NULL, NULL};

  mark = i;
  if (!doc->inside_link || is_image)
    i += parse_link_target(doc, &spec, data + i, size - i, &content_text);

  // Render!
  if (spec) {
    // We have a valid link
    parse_string(doc, target, data + parsed, start - parsed);
    doc->rndr.link(target, content, spec->dest, spec->has_title ? spec->title : NULL, is_image, &doc->data);
    doc->rndr.object_pop(content, 1, &doc->data);
    return i;
  } else {
    doc->rndr.object_pop(content, 1, &doc->data);
    // Following hack is to bind [] even if it's not a valid link
    parse_string(doc, target, data + parsed, label_start - parsed);
    parse_inline(doc, target, data + label_start, label_end - label_start, 0, NULL, NULL);
    parse_string(doc, target, data + label_end, mark - label_end);
    return mark;
  }
}

// data[0] is assumed to be '<'
static inline size_t parse_cdata(const uint8_t *data, size_t size) {
  size_t i = 0;

  // Starting prefix
  if (size >= 9 && memcmp(data, "<![CDATA[", 9) == 0) i += 9;
  else return 0;

  // Content
  size -= 2;
  while (i < size && !(data[i] == ']' && data[i+1] == ']' && data[i+2] == '>')) i++;

  if (i < size) return i + 3;
  return 0;
}

// data[0] is assumed to be '<'
static inline size_t parse_processing_instruction(const uint8_t *data, size_t size) {
  size_t i = 1;

  // Starting prefix
  if (i < size && data[i] == '?') i++;
  else return 0;

  // Content
  size -= 1;
  while (i < size && !(data[i] == '?' && data[i+1] == '>')) i++;

  if (i < size) return i + 2;
  return 0;
}

// data[0] is assumed to be '<'
static inline size_t parse_declaration(const uint8_t *data, size_t size) {
  size_t i = 1, mark;

  // Starting prefix
  if (i < size && data[i] == '!') i++;
  else return 0;

  // Name
  mark = i;
  while (i < size && is_upper_ascii(data[i])) i++;
  if (mark == i) return 0;

  // Spacing
  mark = i;
  while (i < size && is_space(data[i])) i++;
  if (mark == i) return 0;

  // Rest of tag
  while (i < size && data[i] != '>') i++;

  if (i < size) return i + 1;
  return 0;
}

// data[start] is assumed to be a valid emphasis delimiter
static int check_emphasis_end(hoedown_document *doc, const uint8_t *data, size_t parsed, size_t start, size_t size, void *opaque) {
  uint8_t delimiter = data[start];
  size_t i = start;
  size_t *count = opaque;

  // Validate end delimiter
  if (parsed < start && (data[start-1] == delimiter || is_space(data[start-1]))) return 0;

  // Count number of characters in the delimiter
  i++;
  while (i < size && data[i] == delimiter) i++;
  *count = i - start;

  // Further validate delimiter
  if (delimiter == '_' && !(doc->ft & HOEDOWN_FT_INTRA_EMPHASIS) && i < size && is_alnum_ascii(data[i])) return 0;
  if (*count > 3) return 0;

  return 1;
}

// data[start] is assumed to be '*' or '_'
static inline size_t parse_emphasis(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  uint8_t delimiter = data[start];
  size_t i = start, mark;
  size_t open, close, total_open;
  void *content;

  void *reserved_objects [3];
  size_t reserved_count = 3;

  //FIXME: refactor the object allocation part

  // Validate start delimiter
  if (parsed < start && data[start-1] == delimiter) return 0;
  if (delimiter == '_' && !(doc->ft & HOEDOWN_FT_INTRA_EMPHASIS) && parsed < start && is_alnum_ascii(data[start-1])) return 0;

  // Count number of characters in the delimiter
  i++;
  while (i < size && data[i] == delimiter) i++;
  open = i - start;

  // Furter validate delimiter
  if (i < size && is_space(data[i])) return 0;
  if (open > 3) return 0;
  total_open = open;

  // We can't allocate on the way, since that wouldn't be
  // stack-based. So we reserve all three objects now.
  reserved_objects[0] = doc->rndr.object_get(1, &doc->data);
  reserved_objects[1] = doc->rndr.object_get(1, &doc->data);
  reserved_objects[2] = doc->rndr.object_get(1, &doc->data);

  // Parse the content of our [nested] emphasis
  content = doc->rndr.object_get(1, &doc->data);
  while (1) {
    void *subcontent = doc->rndr.object_get(1, &doc->data);
    mark = i;
    i += parse_inline(doc, subcontent, data + i, size - i, delimiter, check_emphasis_end, &close);

    if (i >= size) {
      // No delimiter found
      doc->rndr.object_pop(subcontent, 1, &doc->data);
      i = mark;
      break;
    }

    // [Nested] emphasis of level `close` was found! Render it
    if (close >= open) close = open;

    doc->rndr.object_merge(content, subcontent, 1, &doc->data);
    subcontent = content;
    content = reserved_objects[--reserved_count];
    doc->rndr.emphasis(content, subcontent, close, &doc->data);

    i += close;
    open -= close;
    if (!open) break;
  }

  if (total_open > open) {
    // Content now has the top-level parsed emphasis, merge!
    start += open;
    parse_string(doc, target, data + parsed, start - parsed);
    doc->rndr.object_merge(target, content, 1, &doc->data);
  } else {
    doc->rndr.object_pop(content, 1, &doc->data);
    i = 0;
  }

  // Deallocate (merge) unused objects
  while (reserved_count) doc->rndr.object_pop(reserved_objects[--reserved_count], 1, &doc->data);
  return i;
}


// BLOCK PARSING

// This is the fallback parsing function for block parsing.
static inline void parse_paragraph(hoedown_document *doc, void *target, const uint8_t *data, size_t size) {
  if (size == 0 || doc->mode != NORMAL_PARSING) return;

  size_t content_start = 0, content_end = size;
  while (content_start < size && is_space(data[content_start])) content_start++;
  while (content_end > content_start && is_space(data[content_end-1])) content_end--;

  void *content = doc->rndr.object_get(1, &doc->data);
  parse_inline(doc, content, data + content_start, content_end - content_start, 0, NULL, NULL);
  doc->rndr.paragraph(target, content, doc->is_tight == doc->current_nesting, &doc->data);
  doc->rndr.object_pop(content, 1, &doc->data);
}

static inline int test_atx_header(const uint8_t *data, size_t size) {
  return size >= 1 && (data[0] == '#' || (data[0] == ' ' &&
         size >= 2 && (data[1] == '#' || (data[1] == ' ' &&
         size >= 3 && (data[2] == '#' || (data[2] == ' ' &&
         size >= 4 && (data[3] == '#')))))));
}

static inline size_t parse_atx_header_end(const uint8_t *data, size_t size) {
  size_t i = size, mark;

  // Forget about trailing spaces
  while (i > 0 && data[i-1] == ' ') i--;
  size = i;

  // Retract to skip trailing hashes
  mark = i;
  while (i > 0 && data[i-1] == '#') i--;
  if (i == mark) return size;

  // Check that they're present, and not escaped
  if (is_escaped(data, i)) return size;

  // Retract again to skip spaces between content and hashes
  mark = i;
  while (i > 0 && data[i-1] == ' ') i--;
  if (i == mark && i > 0) return size;

  return i;
}

static inline size_t parse_atx_header(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark, content_start;
  size_t level;

  // Initial spaces
  mark = i;
  while (i < size && data[i] == ' ') i++;
  if ((i - mark) > 3) return 0;

  // Hashes
  mark = i;
  while (i < size && data[i] == '#') i++;
  level = i - mark;
  if (level == 0 || level > 6) return 0;

  // Mandatory spaces
  mark = i;
  while (i < size && data[i] == ' ') i++;
  if (mark == i && data[i] != '\n') return 0;

  content_start = i;

  // Skip until end of line, determine end of content
  while (i < size && data[i] != '\n') i++;
  mark = content_start + parse_atx_header_end(data + content_start, i - content_start);
  
  // Skip past newline
  if (i < size) i++;

  // Render!
  if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
  
    void *content = doc->rndr.object_get(1, &doc->data);
    parse_inline(doc, content, data + content_start, mark - content_start, 0, NULL, NULL);
    doc->rndr.atx_header(target, content, level, &doc->data);
    doc->rndr.object_pop(content, 1, &doc->data);
  }

  return i;
}

static inline size_t parse_setext_header(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark, content_start, content_end;
  uint8_t character;

  // Skip indentation
  mark = i;
  while (i < size && data[i] == ' ') i++;
  if (i - mark > 3) return 0;

  // Skip until next line
  content_start = i;
  while (i < size && data[i] != '\n') i++;
  if (i >= size || content_start == i) return 0;
  content_end = i;
  i++; // skip past newline

  // Skip indentation
  mark = i;
  while (i < size && data[i] == ' ') i++;
  if (i >= size || i - mark > 3) return 0;

  // Collect first character
  character = data[i];
  if (character == '-' || character == '=') i++;
  else return 0;

  // Collect rest of the characters, then trailing spaces
  while (i < size && data[i] == character) i++;
  while (i < size && data[i] == ' ') i++;

  // Line should end here
  if (i < size && data[i] != '\n') return 0;
  i++;

  // Trim spaces on content
  while (content_start < content_end && data[content_start] == ' ') content_start++;
  while (content_end > content_start && data[content_end-1] == ' ') content_end--;

  // Render!
  if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
  
    void *content = doc->rndr.object_get(1, &doc->data);
    parse_inline(doc, content, data + content_start, content_end - content_start, 0, NULL, NULL);
    doc->rndr.setext_header(target, content, character == '=', &doc->data);
    doc->rndr.object_pop(content, 1, &doc->data);
  }

  return i;
}

//FIXME: test_horizontal_rule

static inline size_t parse_horizontal_rule(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start;
  uint8_t character;
  size_t count;

  // Skip three optional spaces
  if (unlikely(i + 3 > size)) return 0;

  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  }}}

  // Collect valid character
  if (unlikely(i >= size)) return 0;

  character = data[i];
  if (character == '*' || character == '-' || character == '_') i++;
  else return 0;

  count = 1;

  // Collect rest of characters until end of line
  while (1) {
    while (i < size && data[i] == ' ') i++;

    if (i < size && data[i] == character) {
      i++;
      count++;
    } else break;
  }

  // Verify there's at least three characters, and end of line
  if (count < 3) return 0;

  if (likely(i < size)) {
    if (data[i] == '\n') i++;
    else return 0;
  }

  // Render!
  if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
  
    doc->rndr.horizontal_rule(target, &doc->data);
  }

  return i;
}

static inline int test_indented_code_block(const uint8_t *data, size_t size) {
  return size > 4 && data[0] == ' ' && data[1] == ' ' && data[2] == ' ' && data[3] == ' ';
}

static inline size_t parse_indented_code_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark;
  size_t last_non_empty_line = 0;
  hoedown_buffer *code = hoedown_pool_get(&doc->buffers_block);
  code->size = 0;
  
  while (1) {
    // Parse initial spaces
    mark = i;
    while (i < size && data[i] == ' ') i++;

    if (i >= size) break;
    if (i < mark + 4 && data[i] != '\n') break;

    // If line is non-empty, set the length later
    if (data[i] != '\n') last_non_empty_line = 0;

    // Add rest of line to working buffer
    mark += 4;
    if (i < mark) mark = i;

    while (i < size && data[i] != '\n') i++;
    if (i < size) i++;
    hoedown_buffer_put(code, data + mark, i - mark);
    if (!last_non_empty_line) last_non_empty_line = code->size;
  }

  // Rewind i to the line start
  i = mark;

  // Rewind the work buffer to cut empty lines at the end
  code->size = last_non_empty_line;

  // Render!
  if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
  
    doc->rndr.indented_code_block(target, code, &doc->data);
  }

  hoedown_pool_pop(&doc->buffers_block, code);
  return i;
}

static inline size_t parse_code_fence(const uint8_t *data, size_t size, uint8_t *character, size_t *width) {
  size_t i = 0, mark;
  
  // Skip three optional spaces
  if (unlikely(i + 3 > size)) return 0;

  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  }}}

  // Process first character
  if (i >= size) return 0;
  *character = data[i];
  mark = i;
  if (*character == '~' || *character == '`') i++;
  else return 0;

  // Process rest of fence
  while (i < size && data[i] == *character) i++;
  if ((*width = i - mark) < 3) return 0;

  return i;
}

//FIXME: test_fenced_code_block

static inline size_t parse_fenced_code_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark;
  size_t indentation, start_width, end_width;
  uint8_t start_character, end_character;
  
  // Parse initial fence
  mark = i;
  i += parse_code_fence(data + i, size - i, &start_character, &start_width);
  if (mark == i) return 0;
  indentation = (i - mark) - start_width;

  // Parse optional info string
  while (i < size && data[i] == ' ') i++;

  mark = i;
  while (i < size && data[i] != '`' && data[i] != '\n') i++;
  if (unlikely(i < size && data[i] == '`')) return 0;

  hoedown_buffer *info = NULL;
  
  if (doc->mode == NORMAL_PARSING) {
    info = hoedown_pool_get(&doc->buffers_inline);
    info->size = 0;
    unescape_both(doc, info, data + mark, i - mark);
    while (info->size > 0 && info->data[info->size-1] == ' ') info->size--;
  }

  if (i < size) i++;

  // Parse the content
  if (unlikely(indentation) && doc->mode == NORMAL_PARSING) {
    hoedown_buffer *code = hoedown_pool_get(&doc->buffers_block);
    code->size = 0;

    size_t line_start;
    while (i < size) {
      // Advance until end of line
      line_start = i;
      while (i < size && data[i] != '\n') i++;
      if (i < size) i++;

      // Check if there's an ending fence here
      mark = parse_code_fence(data + line_start, i - line_start, &end_character, &end_width);

      if (mark && start_character == end_character && start_width <= end_width &&
          is_empty(data + line_start + mark, i - line_start - mark))
        break;

      // Skip optional indentation
      mark = line_start;
      while (mark < size && data[mark] == ' ' && mark - line_start < indentation) mark++;

      // Copy line into work buffer
      hoedown_buffer_put(code, data + mark, i - mark);
    }

    // Render!
    parse_paragraph(doc, target, data + parsed, start - parsed);

    doc->rndr.fenced_code_block(target, code, info->size ? info : NULL, &doc->data);
    hoedown_pool_pop(&doc->buffers_block, code);
  } else {
    // Optimization: When indentation is 0 we don't need intermediate buffers.
    size_t text_start = i, line_start;
    while (1) {
      line_start = i;
      if (i >= size) break;
      
      // Advance until end of line
      while (i < size && data[i] != '\n') i++;
      if (i < size) i++;

      // Check if there's an ending fence here
      mark = parse_code_fence(data + line_start, i - line_start, &end_character, &end_width);

      if (mark && start_character == end_character && start_width <= end_width &&
          is_empty(data + line_start + mark, i - line_start - mark))
        break;
    }

    // Render!
    if (doc->mode == NORMAL_PARSING) {
      parse_paragraph(doc, target, data + parsed, start - parsed);
  
      hoedown_buffer code = {(uint8_t *)data + text_start, line_start - text_start, 0, 0, NULL, NULL};
      doc->rndr.fenced_code_block(target, &code, info->size ? info : NULL, &doc->data);
    }
  }

  if (doc->mode == NORMAL_PARSING)
    hoedown_pool_pop(&doc->buffers_inline, info);

  return i;
}

static inline int test_html_block(const uint8_t *data, size_t size) {
  return size >= 1 && (data[0] == '<' || (data[0] == ' ' &&
         size >= 2 && (data[1] == '<' || (data[1] == ' ' &&
         size >= 3 && (data[2] == '<' || (data[2] == ' ' &&
         size >= 4 && (data[3] == '<')))))));
}

static inline size_t parse_html_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, content_start, mark;

  // Skip three optional spaces
  if (unlikely(i + 3 > size)) return 0;

  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  }}}

  // Check for initial '<'
  if (data[i] != '<') return 0;
  content_start = i;

  // Advance until empty line
  while (1) {
    mark = i;
    while (i < size && data[i] == ' ') i++;

    if (i < size && data[i] != '\n') i++;
    else break;

    while (i < size && data[i] != '\n') i++;
    if (i < size) i++;
  }

  // Try to parse various constructs with a mega-if
  const uint8_t *html_data = data + content_start;
  size_t html_size = mark - content_start;
  hoedown_buffer *name = hoedown_pool_get(&doc->buffers_inline);

  if (
    // HTML start / end tag
    (
      (html_parse_start_tag(name, html_data, html_size) ||
       html_parse_end_tag(name, html_data, html_size))
      && hoedown_find_block_tag((const char *)name->data, name->size)
    )

    // HTML comment
    || html_parse_comment(html_data, html_size)

    // CDATA section
    || parse_cdata(html_data, html_size)

    // Processing instruction
    || parse_processing_instruction(html_data, html_size)

    // Declaration
    || parse_declaration(html_data, html_size)
  ) {
    hoedown_pool_pop(&doc->buffers_inline, name);
    
    // Render!
    if (doc->mode == NORMAL_PARSING) {
      parse_paragraph(doc, target, data + parsed, start - parsed);
  
      hoedown_buffer html = {(uint8_t *)html_data, html_size, 0, 0, NULL, NULL};
      doc->rndr.html_block(target, &html, &doc->data);
    }

    return i;
  }

  hoedown_pool_pop(&doc->buffers_inline, name);
  return 0;
}

static inline int test_link_reference(const uint8_t *data, size_t size) {
  return size >= 1 && (data[0] == '[' || (data[0] == ' ' &&
         size >= 2 && (data[1] == '[' || (data[1] == ' ' &&
         size >= 3 && (data[2] == '[' || (data[2] == ' ' &&
         size >= 4 && (data[3] == '[')))))));
}

// Marker parsing method.
static inline size_t parse_link_reference(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark, label_start, label_end;
  struct link_ref *ref = NULL;

  // Skip three optional spaces
  if (unlikely(i + 3 > size)) return 0;

  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  if (data[i] == ' ') { i++;
  }}}

  // Label starting delimiter
  if (i < size && data[i] == '[') i++;
  else return 0;

  // Find label ending delimiter
  // FIXME: spec doesn't clarify wether newlines are allowed here
  mark = i;
  size_t level = 0;
  while (1) {
    while (i < size && data[i] != ']' && data[i] != '[') i++;
    if (i >= size) return 0;

    if (is_escaped(data, i)) {
      i++;
      continue;
    }

    if (likely(data[i] == ']')) {
      if (level == 0) break;
      level--;
    } else level++;

    i++;
  }

  label_start = mark;
  label_end = i;
  i++;

  // Colon and spacing, up to one newline
  if (i < size && data[i] == ':') i++;
  else return 0;

  while (i < size && data[i] == ' ') i++;
  if (i < size && data[i] == '\n') {
    i++;
    while (i < size && data[i] == ' ') i++;
  }

  // Link spec
  if (doc->mode == MARKER_PARSING)
    ref = hoedown_pool_get(&doc->marker_link_refs);

  mark = i;
  i += parse_link_spec(doc, ref, data + i, size - i);
  if (mark == i) {
    if (ref) hoedown_pool_pop(&doc->marker_link_refs, ref);
    return 0;
  }

  // Rest of line must be empty
  mark = i;
  i += next_line_empty(data + i, size - i);
  if (mark == i && i < size) {
    if (ref) hoedown_pool_pop(&doc->marker_link_refs, ref);
    return 0;
  }

  // Store!
  if (doc->mode == MARKER_PARSING) {
    // Hash the label to get ID
    hoedown_buffer *label = hoedown_pool_get(&doc->buffers_inline);
    label->size = 0;
    collapse_spacing(label, data + label_start, label_end - label_start);
    ref->id = hash_string(label->data, label->size);
    hoedown_pool_pop(&doc->buffers_inline, label);

    // If another reference with same ID exists, return
    if (find_link_ref(doc, ref->id)) {
      hoedown_pool_pop(&doc->marker_link_refs, ref);
      return 0;
    }

    // Store entry
    add_link_ref(doc, ref);
  } else if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
  }
  return i;
}

static inline size_t parse_quote_block_prefix(const uint8_t *data, size_t size) {
  size_t i = 0;

  // Skip three optional spaces
  while (i < size && data[i] == ' ') i++;
  if (i >= 4) return 0;

  // Angle bracket
  if (i < size && data[i] == '>') i++;
  else return 0;

  // Optional space
  if (i < size && data[i] == ' ') i++;

  return i;
}

// The strategy here is: enter dumb parsing mode and collect the quote block
// content to `work`. When an empty line is reached, we break the loop.
// When we have finished collecting content, restore parsing mode and parse it.
//
// If we find a lazy line, we [dumb-]parse the content (starting from
// `parsed`) with these lazy lines to see if they are valid lazy lines;
// we break if they aren't.
static inline size_t parse_quote_block_content(hoedown_document *doc, void *content, hoedown_buffer *work, const uint8_t *data, size_t size) {
  size_t i = 0, mark;
  size_t parsed = 0, current_size;
  enum parsing_mode original_mode = doc->mode;
  doc->mode = DUMB_PARSING;
  //FIXME: refactor

  while (1) {
    mark = i;
    while (i < size && data[i] == ' ') i++;

    // Empty line always ends the quote block
    if (i >= size || data[i] == '\n') break;

    // A prefixed line continues the block
    if (i - mark < 4 && data[i] == '>') {
      i++;
      if (i < size && data[i] == ' ') i++;

      // Put line into working buffer
      mark = i;
      while (i < size && data[i] != '\n') i++;
      if (i < size) i++;

      hoedown_buffer_put(work, data + mark, i - mark);
      continue;
    }

    // Possible lazy line, collect this and following possible lazy lines
    i = mark;
    current_size = work->size;
    while (1) {
      if (parse_any_block(doc, NULL, data, i, i, size, size, 0)) break;

      while (i < size && data[i] != '\n') i++;
      if (i < size) i++;

      if (i >= size || next_line_empty(data + i, size - i) || parse_quote_block_prefix(data + i, size - i))
        break;
    }
    hoedown_buffer_put(work, data + mark, i - mark);

    // If the next line is prefixed, the block could continue.
    // Otherwise, we can be sure it ends here and return immediately.
    if (parse_quote_block_prefix(data + i, size - i)) {
      // Can these lines continue the block?
      parsed += parse_block(doc, NULL, work->data + parsed, current_size - parsed, work->size - parsed, HOEDOWN_FT_QUOTE_BLOCK | HOEDOWN_FT_LIST);
      if (parsed == current_size) {
        work->size = current_size;
        break;
      }
      parsed = work->size;
    } else {
      // Definitively parse and return
      doc->mode = original_mode;
      parsed = parse_block(doc, content, work->data, current_size, work->size, HOEDOWN_FT_QUOTE_BLOCK | HOEDOWN_FT_LIST);
      if (parsed == current_size) {
        work->size = current_size;
        return mark;
      }

      // These are valid lazy lines, parse reminder if present and return
      if (parsed < current_size) parse_block(doc, content, work->data + parsed, work->size - parsed, work->size - parsed, 0);
      return i;
    }
  }

  // Actually parse collected content
  doc->mode = original_mode;
  parse_block(doc, content, work->data, work->size, work->size, 0);
  return mark;
}

// This block construct is a container.
static inline size_t parse_quote_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start, mark;
  hoedown_buffer *work = NULL;
  void *content = NULL;

  // We should have a quote block prefix here
  mark = i;
  i += parse_quote_block_prefix(data + i, size - i);
  if (mark == i) return 0;

  // Get working buffer & content
  work = hoedown_pool_get(&doc->buffers_block);
  work->size = 0;

  if (doc->mode == NORMAL_PARSING)
    content = doc->rndr.object_get(0, &doc->data);

  // Collect first line
  mark = i;
  while (i < size && data[i] != '\n') i++;
  if (i < size) i++;

  hoedown_buffer_put(work, data + mark, i - mark);

  // Parse rest of content
  i += parse_quote_block_content(doc, content, work, data + i, size - i);

  // Render!
  if (doc->mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
    doc->rndr.quote_block(target, content, &doc->data);
    doc->rndr.object_pop(content, 0, &doc->data);
  }

  hoedown_pool_pop(&doc->buffers_block, work);
  return i;
}

static inline size_t parse_list_marker(const uint8_t *data, size_t size, int *is_ordered, int *number, uint8_t *character) {
  if (size < 1) return 0;

  if (data[0] == '-' || data[0] == '*' || data[0] == '+') {
    *is_ordered = 0;
    *character = data[0];
    return 1;
  }

  if (is_digit_ascii(data[0])) {
    size_t i = 1;
    while (i < size && is_digit_ascii(data[i])) i++;

    if (i < size && (data[i] == '.' || data[i] == ')')) {
      // Parse the integer
      if (number) {
        *number = 0;
        for (size_t a = 0; a < i; a++)
          *number = (*number * 10) + (data[a] - '0');
      }

      *is_ordered = 1;
      *character = data[i];
      return i + 1;
    }
  }

  return 0;
}

static inline size_t parse_list_prefix(const uint8_t *data, size_t size, int *is_ordered, int *number, uint8_t *character) {
  size_t i = 0, mark;
  
  // Optional indentation
  while (i < size && data[i] == ' ') i++;
  if (i >= 4) return 0;

  // Marker
  mark = i;
  i += parse_list_marker(data + i, size - i, is_ordered, number, character);
  if (mark == i) return 0;

  // Followed by spacing or EOF
  if (i < size && !is_space(data[i])) return 0;
  if (i < size && data[i] == ' ') i++;

  return i;
}

//FIXME: test_list

// Should only be called from parse_list_item_content. Tries to resolve if the
// list item ends on that empty line, or continues afterwards. If it continues,
// the point where the list item continues is returned.
static inline size_t parse_list_item_empty(hoedown_document *doc, hoedown_buffer *work, size_t *parsed, int *is_loose, const uint8_t *data, size_t start, size_t size, size_t indentation, size_t empty_start) {
  size_t i = start, mark;
  int multiple_lines = 0;

  // Start by skipping empty lines and finding a non-empty non-lazy line
  // If such a line cannot be found, the list item cannot continue.
  while (1) {
    mark = i + indentation;
    while (i < size && data[i] == ' ') i++;
    if (i >= size) return 0;

    // Empty line is accepted (for now)
    if (data[i] == '\n') {
      if (mark > i) mark = i;
      i++;
      hoedown_buffer_put(work, data + mark, i - mark);
      multiple_lines = 1;
      continue;
    }

    // Lazy line not allowed here
    if (mark > i) return 0;

    // Found a non-empty non-lazy line!
    while (i < size && data[i] != '\n') i++;
    if (i < size) i++;
    hoedown_buffer_put(work, data + mark, i - mark);
    break;
  }

  // If there were no extra lines skipped, just one empty line,
  // then we can be sure it belongs to the block.
  if (!multiple_lines) {
    // But before returning, look if that line makes the list loose
    if (!*is_loose) {
      *parsed += parse_block(doc, NULL, work->data + *parsed, empty_start - *parsed, work->size - *parsed, HOEDOWN_FT_FENCED_CODE_BLOCK | HOEDOWN_FT_LIST);
      *is_loose = *parsed < work->size;
    }

    return i;
  }

  // If we get here there is more than one empty line, and we need
  // to check if these empty lines belong to a fenced code block.
  // Only in that case can the list item continue.
  if (doc->ft & HOEDOWN_FT_FENCED_CODE_BLOCK) {
    *parsed += parse_block(doc, NULL, work->data + *parsed, empty_start - *parsed, work->size - *parsed, HOEDOWN_FT_FENCED_CODE_BLOCK | HOEDOWN_FT_LIST);
    if (*parsed > empty_start) return i;
  }

  return 0;
}

// Gets a new buffer from the block_buffers pool and collects the
// contents of a list item there. Assumes mode is DUMB_PARSING.
static inline size_t parse_list_item_content(hoedown_document *doc, int *is_loose, const uint8_t *data, size_t size, size_t indentation) {
  size_t i = 0, mark, line_start;
  size_t parsed = 0, work_mark;

  hoedown_buffer *work = hoedown_pool_get(&doc->buffers_block);
  work->size = 0;

  // Collect first line, which decides the indentation
  while (i < size && data[i] == ' ') i++;
  if (i < 4 || !(doc->ft & HOEDOWN_FT_INDENTED_CODE_BLOCK)) indentation += i;

  while (i < size && data[i] != '\n') i++;
  if (i < size) i++;
  hoedown_buffer_put(work, data, i);

  // Rest of the lines
  while (i < size) {
    line_start = i;
    mark = i + indentation;
    while (i < size && data[i] == ' ') i++;

    // Empty line is checked
    if (i >= size || data[i] == '\n') {
      if (mark > i) mark = i;
      if (i < size) i++;
      work_mark = work->size;
      hoedown_buffer_put(work, data + mark, i - mark);

      i = parse_list_item_empty(doc, work, &parsed, is_loose, data, i, size, indentation, work_mark);
      if (i) continue;
      work->size = work_mark;
      i = line_start;
      break;
    }

    // Non-empty, lazy line is checked
    if (mark > i) {
      mark = i;
      while (i < size && data[i] != '\n') i++;
      if (i < size) i++;

      //FIXME: refactor this
      if (parse_any_block(doc, NULL, data + mark, 0, 0, i - mark, i - mark, 0)) {
        i = line_start;
        break;
      }
      work_mark = work->size;
      hoedown_buffer_put(work, data + mark, i - mark);

      parsed += parse_block(doc, NULL, data + parsed, work_mark - parsed, work->size - parsed, HOEDOWN_FT_LIST | HOEDOWN_FT_QUOTE_BLOCK);
      if (parsed != work_mark) continue;
      work->size = work_mark;
      i = line_start;
      break;
    }

    // Non-empty, non-lazy line is accepted
    while (i < size && data[i] != '\n') i++;
    if (i < size) i++;
    hoedown_buffer_put(work, data + mark, i - mark);
  }

  return i;
}

// Parse the rest of the list, starting from the end of the first list item.
static inline size_t parse_list_items(hoedown_document *doc, int *is_loose, const uint8_t *data, size_t size, uint8_t character) {
  size_t i = 0, mark;
  size_t last_item = 0;
  int is_ordered;
  uint8_t ncharacter;
  int possible_loose;

  while (i < size) {
    // Optional empty line (which makes list loose)
    mark = i;
    i += next_line_empty(data + i, size - i);
    possible_loose = mark < i;

    // If the item we're about to parse is a rule, break
    if (parse_horizontal_rule(doc, NULL, data, i, i, size)) break;

    // List item prefix of the same type
    mark = i;
    i += parse_list_prefix(data + i, size - i, &is_ordered, NULL, &ncharacter);
    if (mark == i || character != ncharacter) break;

    // List item content
    i += parse_list_item_content(doc, is_loose, data + i, size - i, i - mark);
    last_item = i;
    if (possible_loose) *is_loose = 1;
  }

  return last_item;
}

static inline size_t parse_list(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  int current_is_tight = doc->is_tight;
  int current_mode = doc->mode;
  size_t current_pool_position = doc->buffers_block.size;

  size_t i = start, mark;
  int is_ordered, is_loose, number = 0;
  uint8_t character;
  void *content = NULL;

  // Collect first list item
  mark = i;
  i += parse_list_prefix(data + i, size - i, &is_ordered, &number, &character);
  if (mark == i) return 0;

  is_loose = 0;
  doc->mode = DUMB_PARSING;
  i += parse_list_item_content(doc, &is_loose, data + i, size - i, i - mark);

  // Collect rest of the items
  i += parse_list_items(doc, &is_loose, data + i, size - i, character);

  // Actually parse and render each list item
  if (!is_loose) doc->is_tight = doc->current_nesting + 1;
  doc->mode = current_mode;
  if (current_mode == NORMAL_PARSING)
    content = doc->rndr.object_get(0, &doc->data);

  for (size_t a = current_pool_position; a < doc->buffers_block.size; a++) {
    hoedown_buffer *work = doc->buffers_block.item[a];
    void *item_content = NULL;
    if (current_mode == NORMAL_PARSING)
      item_content = doc->rndr.object_get(0, &doc->data);

    if (current_mode != DUMB_PARSING)
      parse_block(doc, item_content, work->data, work->size, work->size, 0);

    if (current_mode == NORMAL_PARSING) {
      doc->rndr.list_item(content, item_content, is_ordered, !is_loose, &doc->data);
      doc->rndr.object_pop(item_content, 0, &doc->data);
    }
  }

  // Render the list itself
  doc->is_tight = current_is_tight;
  doc->buffers_block.size = current_pool_position;

  if (current_mode == NORMAL_PARSING) {
    parse_paragraph(doc, target, data + parsed, start - parsed);
    doc->rndr.list(target, content, is_ordered, !is_loose, number, &doc->data);
    doc->rndr.object_pop(content, 0, &doc->data);
  }
  return i;
}



// BLOCK PARSING
// -------------
//
// Here's the implementation of `parse_block`, the entry point for block
// parsing, and `parse_any_block`, which defines the priorities and
// requirements for all block constructs.
//
// For regular block parsing, `parse_block` should be called with the
// same value in `size` and `lazy_size`.
//
// But if there are lazy lines at the end of the regular content: `lazy_size`
// should be set to the size of the regular content plus the lazy lines.
//
// Lazy lines are only parsed if they belong to a block of type `lazy_ft`.
// Please note that not *all* of the additional content may be parsed, only
// the valid lazy lines. If the returned value equals `size`, there were no
// valid lazy lines parsed.
//
// If the lazy lines were parsed as part of the specified block, returned value
// will be greater than `size`. But if the lazy lines continued a paragraph at
// the end of the regular content, the paragraph (and lazy lines) will not be
// parsed, and the returned value will be less than `size`. Both cases are
// valid lazy lines, but must be handled differently; see i.e. quote blocks.


// Try to parse a block construct at a specific position, which is assumed
// to be the start of a non-empty line.
static inline size_t parse_any_block(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t i, size_t size, size_t lazy_size, hoedown_features lazy_ft) {
  size_t result;

  // Some constructs can't interrupt paragraphs, so we check that parsed == i

  if (doc->ft & HOEDOWN_FT_INDENTED_CODE_BLOCK && parsed == i &&
      test_indented_code_block(data + i, size - i) &&
      (result = parse_indented_code_block(doc, target, data, parsed, i, size)))
    return result;

  if (doc->ft & HOEDOWN_FT_FENCED_CODE_BLOCK &&
      (result = parse_fenced_code_block(doc, target, data, parsed, i,
        lazy_ft & HOEDOWN_FT_FENCED_CODE_BLOCK ? lazy_size : size)))
    return result;

  if (doc->ft & HOEDOWN_FT_HORIZONTAL_RULE &&
      (result = parse_horizontal_rule(doc, target, data, parsed, i, size)))
    return result;

  if (doc->ft & HOEDOWN_FT_QUOTE_BLOCK &&
      (result = parse_quote_block(doc, target, data, parsed, i,
        lazy_ft & HOEDOWN_FT_QUOTE_BLOCK ? lazy_size : size)))
    return result;

  if (doc->ft & HOEDOWN_FT_LIST &&
      (result = parse_list(doc, target, data, parsed, i,
        lazy_ft & HOEDOWN_FT_LIST ? lazy_size : size)))
    return result;

  if (doc->ft & HOEDOWN_FT_ATX_HEADER &&
      test_atx_header(data + i, size - i) &&
      (result = parse_atx_header(doc, target, data, parsed, i, size)))
    return result;

  if (doc->ft & HOEDOWN_FT_SETEXT_HEADER && parsed == i &&
      (result = parse_setext_header(doc, target, data, parsed, i, size)))
    return result;

  if (doc->ft & HOEDOWN_FT_HTML_BLOCK &&
      test_html_block(data + i, size - i) &&
      (result = parse_html_block(doc, target, data, parsed, i, size)))
    return result;
  
  if (doc->ft & HOEDOWN_FT_LINK && parsed == i &&
      test_link_reference(data + i, size - i) &&
      (result = parse_link_reference(doc, target, data, parsed, i, size)))
    return result;

  return 0;
}


static size_t parse_block(hoedown_document *doc, void *target, const uint8_t *data, size_t size, size_t lazy_size, hoedown_features lazy_ft) {
  if (doc->current_nesting > doc->max_nesting) return size; //FIXME: stop all parsing here
  doc->current_nesting++;

  size_t i = 0, result, parsed = 0;

  while (i < size) {
    // First, check to see if this is an empty line
    // If it is, parse any accumulated content as paragraph, and skip
    if ((result = next_line_empty(data + i, size - i))) {
      parse_paragraph(doc, target, data + parsed, i - parsed);
      i += result;
      parsed = i;
      continue;
    }

    // Try to parse a construct here
    if ((result = parse_any_block(doc, target, data, parsed, i, size, lazy_size, lazy_ft))) {
      i = parsed = result;
      continue;
    }

    // Nothing could be parsed on this line, skip to the next
    while (i < size && data[i] != '\n') i++;
    if (i < size) i++;
  }

  // Parse rest of the content as paragraph
  if (lazy_size == size && parsed < i) {
    parse_paragraph(doc, target, data + parsed, i - parsed);
    parsed = i;
  }

  doc->current_nesting--;
  return parsed;
}



// CHAR TRIGGERS, INLINE PARSING
// -----------------------------
//
// Here's the implementation of `inline_parse`. When it finds an interesting
// character in the input, it looks up the appropiate function (called *char
// trigger*) to process the input at that point.
//
// The char trigger (for example, `char_dollar`) then calls routines to
// parse possible constructs at that point.
//
// If passed a delimiter, `parse_inline` will look for that character in
// unparsed input. If it's found, and the passed check callback accepts it,
// parsing ends at that point.


static size_t char_escape(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start + 1;

  if (i >= size) return 0;

  if (doc->ft & HOEDOWN_FT_ESCAPE && is_punct_ascii(data[i])) {
    parse_string(doc, target, data + parsed, start - parsed);
    doc->rndr.escape(target, data[i], &doc->data);
    return i + 1;
  }

  if (doc->ft & HOEDOWN_FT_HARD_LINEBREAK && data[i] == '\n') {
    parse_string(doc, target, data + parsed, start - parsed);
    doc->rndr.hard_linebreak(target, &doc->data);
    return i + 1;
  }

  return 0;
}

static size_t char_newline(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start;
  // Rewind on all trailing spaces
  while (i > parsed && data[i-1] == ' ') i--;

  if (doc->ft & HOEDOWN_FT_LINEBREAK && start - i >= 2) {
    parse_string(doc, target, data + parsed, i - parsed);
    doc->rndr.hard_linebreak(target, &doc->data);
    return start + 1;
  }

  //FIXME: SOFT_LINEBREAK

  if (i == start) return 0;
  parse_string(doc, target, data + parsed, i - parsed);
  parse_string(doc, target, data + start, 1);
  return start + 1;
}

static size_t char_angle_bracket(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t result;

  if (doc->ft & HOEDOWN_FT_URI_AUTOLINK &&
      (result = parse_uri_autolink(doc, target, data, parsed, start, size)))
    return result;


  if (!(doc->ft & HOEDOWN_FT_HTML)) return 0;

  const uint8_t *cur_data = data + start;
  size_t cur_size = size - start;

  if (
        (result = html_parse_start_tag(NULL, cur_data, cur_size)) ||
        (result = html_parse_end_tag(NULL, cur_data, cur_size)) ||
        (result = html_parse_comment(cur_data, cur_size)) ||
        (result = parse_cdata(cur_data, cur_size)) ||
        (result = parse_processing_instruction(cur_data, cur_size)) ||
        (result = parse_declaration(cur_data, cur_size))
      ) {
    parse_string(doc, target, data + parsed, start - parsed);
    hoedown_buffer html = {(uint8_t *)cur_data, result, 0, 0, NULL, NULL};
    doc->rndr.html(target, &html, &doc->data);
    return start + result;
  }

  return 0;
}

static size_t char_backtick(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  return parse_code_span(doc, target, data, parsed, start, size);
}

static size_t char_ampersand(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  size_t i = start + 1;

  hoedown_buffer *character = hoedown_pool_get(&doc->buffers_inline);
  character->size = 0;
  i += hoedown_unescape_entity(character, data + i, size - i);

  if (i > start + 1) {
    parse_string(doc, target, data + parsed, start - parsed);

    doc->rndr.entity(target, character, &doc->data);
    hoedown_pool_pop(&doc->buffers_inline, character);
    return i;
  }

  hoedown_pool_pop(&doc->buffers_inline, character);
  return 0;
}

static size_t char_star(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  return parse_emphasis(doc, target, data, parsed, start, size);
}

static size_t char_underscore(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  return parse_emphasis(doc, target, data, parsed, start, size);
}

static size_t char_square_bracket(hoedown_document *doc, void *target, const uint8_t *data, size_t parsed, size_t start, size_t size) {
  return parse_link(doc, target, data, parsed, start, size);
}


static size_t parse_inline(hoedown_document *doc, void *target, const uint8_t *data, size_t size, uint8_t delimiter, delimiter_check check, void *opaque) {
  if (doc->current_nesting > doc->max_nesting) return size;
  doc->current_nesting++;
  
  size_t i = 0, result, parsed = 0;
  char_trigger *active_chars = doc->active_chars;
  
  while (i < size) {
    // Skip any chars we're not interested in
    if (delimiter) {
      while (i < size && active_chars[data[i]] == NULL && data[i] != delimiter) i++;
      if (i < size && data[i] == delimiter) {
        // We found the delimiter we were looking for!
        if (!check || check(doc, data, parsed, i, size, opaque)) break;
      }
    } else {
      while (i < size && active_chars[data[i]] == NULL) i++;
    }

    if (i >= size) break;

    // Call the char trigger, see if we can parse something here
    if (active_chars[data[i]] && (result = active_chars[data[i]](doc, target, data, parsed, i, size))) {
      parsed = i = result;
      continue;
    }

    // Okay, skip this character and move on
    i++;
  }

  // Parse rest of content as string
  parse_string(doc, target, data + parsed, i - parsed);

  doc->current_nesting--;
  return i;
}

static inline void set_active_chars(char_trigger *active_chars, hoedown_features ft) {
  memset(active_chars, 0, 256 * sizeof(char_trigger *));

  if (ft & (HOEDOWN_FT_ESCAPE | HOEDOWN_FT_MATH))
    active_chars['\\'] = char_escape;

  if (ft & (HOEDOWN_FT_HARD_LINEBREAK | HOEDOWN_FT_LINEBREAK | HOEDOWN_FT_SOFT_LINEBREAK))
    active_chars['\n'] = char_newline;

  if (ft & (HOEDOWN_FT_HTML | HOEDOWN_FT_URI_AUTOLINK | HOEDOWN_FT_EMAIL_AUTOLINK))
    active_chars['<'] = char_angle_bracket;

  if (ft & (HOEDOWN_FT_CODE_SPAN))
    active_chars['`'] = char_backtick;

  if (ft & (HOEDOWN_FT_ENTITY))
    active_chars['&'] = char_ampersand;

  if (ft & (HOEDOWN_FT_EMPHASIS))
    active_chars['*'] = char_star;

  if (ft & (HOEDOWN_FT_EMPHASIS))
    active_chars['_'] = char_underscore;

  if (ft & (HOEDOWN_FT_LINK))
    active_chars['['] = char_square_bracket;
}



// PUBLIC METHODS & MISC
// ---------------------
//
// There it is. The public entry point for rendering. The method prepares the
// `hoedown_document` struct for a render, calls `parse_block` or
// `parse_inline` as appropiate, then cleans everything up.
//
// Other things can be implemented here, such as exposed internal methods.


static inline void restrict_features(const hoedown_renderer *rndr, hoedown_features *ft) {
  hoedown_features not_present = 0;
  
  //TODO
  
  // Remove not present features from *ft
  *ft &= ~not_present;
}


static inline void expand_tabs(hoedown_buffer *ob, const uint8_t *data, size_t i, size_t size) {
  size_t mark;
  size_t isize = ob->size;
  static const uint8_t *tab = (const uint8_t *)"    ";

  while (i < size) {
    mark = i;
    while (1) {
      // Advance until we find a tab, but keep multi-byte characters in mind
      while (i < size && (data[i] & 0xc0) != 0x80 && data[i] != '\t') i++;
      if (i >= size || data[i] == '\t') break;
      // this byte should not be counted
      i++; isize++;
    }

    hoedown_buffer_put(ob, data + mark, i - mark);
    if (i >= size) break;

    hoedown_buffer_put(ob, tab, 4 - (ob->size - isize) % 4);
    i++;
  }
}

void hoedown_preprocess(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0, mark;
  hoedown_buffer_grow(ob, size);

  while (1) {
    mark = i;
    while (i < size && data[i] != '\n' && data[i] != '\r') i++;
    expand_tabs(ob, data, mark, i);

    if (i >= size) break;

    if (data[i] == '\r') i++;
    if (i < size && data[i] == '\n') i++;
    hoedown_buffer_putc(ob, '\n');
  }
}

void *hoedown_document_render(
  hoedown_document *doc,
  const uint8_t *data, size_t size,
  int is_inline, void *request
) {
  // Initialize everything
  memset(&doc->link_refs_table, 0, sizeof(doc->link_refs_table));

  // Preprocess the input
  if (doc->ft & HOEDOWN_FT_PREPROCESS) {
    hoedown_preprocess(doc->text, data, size);
    data = doc->text->data;
    size = doc->text->size;
    doc->text->size = 0;
  }

  // Prepare
  doc->data.request = request;
  doc->rndr.render_start(is_inline, &doc->data);

  // First, parse the markers
  doc->mode = MARKER_PARSING;
  if (!is_inline)
    parse_block(doc, NULL, data, size, size, 0);

  // Render!
  doc->mode = NORMAL_PARSING;
  void *target = doc->rndr.object_get(is_inline, &doc->data);
  if (is_inline)
    parse_inline(doc, target, data, size, 0, NULL, NULL);
  else
    parse_block(doc, target, data, size, size, 0);

  // Finish & cleanup
  doc->marker_link_refs.size = 0;
  assert(doc->current_nesting == 0);
  assert(doc->buffers_block.size == 0);
  assert(doc->buffers_inline.size == 0);

  assert(doc->emphasis_stack.size == 0);
  assert(doc->emphasis_stack.initial_size == 0);
  assert(doc->emphasis_stack.current_target == NULL);

  return doc->rndr.render_end(target, is_inline, &doc->data);
}
