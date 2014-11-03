#include "escape.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#define _isxdigit(c) (strchr("0123456789ABCDEFabcdef", (c)) != NULL)
#define _isdigit(c) ((c) >= '0' && (c) <= '9')

#include "_html_entities.h"


/*
 * The following characters will not be escaped:
 *
 *    -_.+!*'(),%#@?=;:/,+&$ alphanum
 *
 * Note that this character set is the addition of:
 *
 *  - The characters which are safe to be in an URL
 *  - The characters which are *not* safe to be in
 *  an URL because they are RESERVED characters.
 *
 * We asume (lazily) that any RESERVED char that
 * appears inside an URL is actually meant to
 * have its native function (i.e. as an URL
 * component/separator) and hence needs no escaping.
 *
 * There are two exceptions: the chacters & (amp)
 * and ' (single quote) do not appear in the table.
 * They are meant to appear in the URL as components,
 * yet they require special HTML-entity escaping
 * to generate valid HTML markup.
 *
 * All other characters will be escaped to %XX.
 *
 */
static const uint8_t HREF_SAFE[UINT8_MAX+1] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void hoedown_escape_href(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  static const char hex_chars[] = "0123456789ABCDEF";
  size_t  i = 0, mark;
  char hex_str[3];

  hex_str[0] = '%';

  while (i < size) {
    mark = i;
    while (i < size && HREF_SAFE[data[i]]) i++;

    /* Optimization for cases where there's nothing to escape */
    if (mark == 0 && i >= size) {
      hoedown_buffer_put(ob, data, size);
      return;
    }

    if (likely(i > mark)) {
      hoedown_buffer_put(ob, data + mark, i - mark);
    }

    /* escaping */
    if (i >= size)
      break;

    switch (data[i]) {
    /* amp appears all the time in URLs, but needs
     * HTML-entity escaping to be inside an href */
    case '&':
      HOEDOWN_BUFPUTSL(ob, "&amp;");
      break;

    /* the single quote is a valid URL character
     * according to the standard; it needs HTML
     * entity escaping too */
    case '\'':
      HOEDOWN_BUFPUTSL(ob, "&#x27;");
      break;

    /* the space can be escaped to %20 or a plus
     * sign. we're going with the generic escape
     * for now. the plus thing is more commonly seen
     * when building GET strings */
#if 0
    case ' ':
      hoedown_buffer_putc(ob, '+');
      break;
#endif

    /* every other character goes with a %XX escaping */
    default:
      hex_str[1] = hex_chars[(data[i] >> 4) & 0xF];
      hex_str[2] = hex_chars[data[i] & 0xF];
      hoedown_buffer_put(ob, (uint8_t *)hex_str, 3);
    }

    i++;
  }
}


/**
 * According to the OWASP rules:
 *
 * & --> &amp;
 * < --> &lt;
 * > --> &gt;
 * " --> &quot;
 * ' --> &#x27;     &apos; is not recommended
 * / --> &#x2F;     forward slash is included as it helps end an HTML entity
 *
 */
static const uint8_t HTML_ESCAPE_TABLE[UINT8_MAX+1] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 5, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static const char *HTML_ESCAPES[] = {
        "",
        "&quot;",
        "&amp;",
        "&#39;",
        "&lt;",
        "&gt;"
};

void hoedown_escape_html(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0, mark;

  while (1) {
    mark = i;
    while (i < size && HTML_ESCAPE_TABLE[data[i]] == 0) i++;

    /* Optimization for cases where there's nothing to escape */
    if (mark == 0 && i >= size) {
      hoedown_buffer_put(ob, data, size);
      return;
    }

    if (likely(i > mark))
      hoedown_buffer_put(ob, data + mark, i - mark);

    if (i >= size) break;

    hoedown_buffer_puts(ob, HTML_ESCAPES[HTML_ESCAPE_TABLE[data[i]]]);
    i++;
  }
}

void hoedown_escape_character(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  if (size == 1 && HTML_ESCAPE_TABLE[data[0]]) {
    hoedown_buffer_puts(ob, HTML_ESCAPES[HTML_ESCAPE_TABLE[data[0]]]);
    return;
  }
  /* Character doesn't need escaping */
  hoedown_buffer_put(ob, data, size);
}



size_t hoedown_unescape_entity(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0;

  if (size > 3 && data[0] == '#') {
    int codepoint = 0;

    if (_isdigit(data[1])) {
      for (i = 1; i < size && _isdigit(data[i]); ++i)
        codepoint = (codepoint * 10) + (data[i] - '0');
    }

    else if (data[1] == 'x' || data[1] == 'X') {
      for (i = 2; i < size && _isxdigit(data[i]); ++i)
        codepoint = (codepoint * 16) + ((data[i] | 32) % 39 - 9);
      if (i == 2) return 0;
    }

    if (i < size && data[i] == ';') {
      hoedown_buffer_put_utf8(ob, codepoint);
      return i + 1;
    }
  }

  else {
    if (size > MAX_WORD_LENGTH)
      size = MAX_WORD_LENGTH;

    for (i = MIN_WORD_LENGTH; i < size; ++i) {
      if (data[i] == ' ')
        break;

      if (data[i] == ';') {
        const struct html_entity *entity = find_entity((const char *)data, i);

        if (entity != NULL) {
          hoedown_buffer_put(ob, entity->utf8, entity->size);
          return i + 1;
        }

        break;
      }
    }
  }

  return 0;
}

void hoedown_unescape_html(hoedown_buffer *ob, const uint8_t *data, size_t size) {
  size_t i = 0, mark = 0;
  while (1) {
    while (i < size && data[i] != '&') i++;

    /* Optimization for cases where there's nothing to escape */
    if (mark == 0 && i >= size) {
      hoedown_buffer_put(ob, data, size);
      return;
    }

    if (likely(i > mark))
      hoedown_buffer_put(ob, data + mark, i - mark);

    if (i >= size) break;

    mark = i;
    i++;
    i += hoedown_unescape_entity(ob, data + i, size - i);
    if (i > mark + 1) mark = i;
  }
}
