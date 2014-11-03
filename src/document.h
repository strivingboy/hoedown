/* document.h - generic markdown parser */

#ifndef HOEDOWN_DOCUMENT_H
#define HOEDOWN_DOCUMENT_H

#include "buffer.h"
#include "autolink.h"

#ifdef __cplusplus
extern "C" {
#endif


/*************
 * CONSTANTS *
 *************/

typedef enum hoedown_features {
  /* Block constructs */
  HOEDOWN_FT_DIRECTIVE = (1 << 0),
  HOEDOWN_FT_INDENTED_CODE_BLOCK = (1 << 1),
  HOEDOWN_FT_FENCED_CODE_BLOCK = (1 << 2),
  HOEDOWN_FT_HORIZONTAL_RULE = (1 << 3),
  HOEDOWN_FT_ATX_HEADER = (1 << 4),
  HOEDOWN_FT_SETEXT_HEADER = (1 << 5),
  HOEDOWN_FT_LIST = (1 << 8),
  HOEDOWN_FT_QUOTE_BLOCK = (1 << 31),
  HOEDOWN_FT_HTML_BLOCK = (1 << 6),
  HOEDOWN_FT_TABLE = (1 << 7),

  /* Inline constructs */
  HOEDOWN_FT_ROLE = (1 << 9),
  HOEDOWN_FT_ESCAPE = (1 << 10),
  HOEDOWN_FT_HARD_LINEBREAK = (1 << 11),
  HOEDOWN_FT_LINEBREAK = (1 << 12),
  HOEDOWN_FT_SOFT_LINEBREAK = (1 << 13),
  HOEDOWN_FT_URI_AUTOLINK = (1 << 14),
  HOEDOWN_FT_EMAIL_AUTOLINK = (1 << 15),
  HOEDOWN_FT_HTML = (1 << 16),
  HOEDOWN_FT_ENTITY = (1 << 17),
  HOEDOWN_FT_CODE_SPAN = (1 << 18),
  HOEDOWN_FT_EMPHASIS = (1 << 19),
  HOEDOWN_FT_LINK = (1 << 20),
  HOEDOWN_FT_MATH = (1 << 22),
  HOEDOWN_FT_SUPERSCRIPT = (1 << 23),
  HOEDOWN_FT_QUOTE = (1 << 24),
  HOEDOWN_FT_STRIKETHROUGH = (1 << 25),
  HOEDOWN_FT_HIGHLIGHT = (1 << 26),
  HOEDOWN_FT_FOOTNOTE = (1 << 27),

  /* Other features */
  HOEDOWN_FT_PREPROCESS = (1 << 28),

  /* Flags */
  HOEDOWN_FT_LINK_IMAGE = (1 << 21),
  HOEDOWN_FT_INTRA_EMPHASIS = (1 << 29),
  HOEDOWN_FT_MATH_EXPLICIT = (1 << 30),
} hoedown_features;


#define HOEDOWN_FT_BLOCK (\
  HOEDOWN_FT_DIRECTIVE |\
  HOEDOWN_FT_INDENTED_CODE_BLOCK |\
  HOEDOWN_FT_FENCED_CODE_BLOCK |\
  HOEDOWN_FT_HORIZONTAL_RULE |\
  HOEDOWN_FT_ATX_HEADER |\
  HOEDOWN_FT_SETEXT_HEADER |\
  HOEDOWN_FT_LIST |\
  HOEDOWN_FT_QUOTE_BLOCK |\
  HOEDOWN_FT_HTML_BLOCK |\
  HOEDOWN_FT_TABLE |\
0)

#define HOEDOWN_FT_INLINE (\
  HOEDOWN_FT_ROLE |\
  HOEDOWN_FT_ESCAPE |\
  HOEDOWN_FT_HARD_LINEBREAK |\
  HOEDOWN_FT_LINEBREAK |\
  HOEDOWN_FT_SOFT_LINEBREAK |\
  HOEDOWN_FT_URI_AUTOLINK |\
  HOEDOWN_FT_EMAIL_AUTOLINK |\
  HOEDOWN_FT_HTML |\
  HOEDOWN_FT_ENTITY |\
  HOEDOWN_FT_CODE_SPAN |\
  HOEDOWN_FT_EMPHASIS |\
  HOEDOWN_FT_LINK |\
  HOEDOWN_FT_MATH |\
  HOEDOWN_FT_SUPERSCRIPT |\
  HOEDOWN_FT_QUOTE |\
  HOEDOWN_FT_STRIKETHROUGH |\
  HOEDOWN_FT_HIGHLIGHT |\
  HOEDOWN_FT_FOOTNOTE |\
0)

#define HOEDOWN_FT_OTHER (\
  HOEDOWN_FT_PREPROCESS |\
0)

#define HOEDOWN_FT_FLAGS (\
  HOEDOWN_FT_LINK_IMAGE |\
  HOEDOWN_FT_INTRA_EMPHASIS |\
  HOEDOWN_FT_MATH_EXPLICIT |\
0)


/***********
 * PRESETS *
 ***********/

#define HOEDOWN_FT_COMMONMARK (\
  HOEDOWN_FT_INDENTED_CODE_BLOCK |\
  HOEDOWN_FT_FENCED_CODE_BLOCK |\
  HOEDOWN_FT_HORIZONTAL_RULE |\
  HOEDOWN_FT_ATX_HEADER |\
  HOEDOWN_FT_SETEXT_HEADER |\
  HOEDOWN_FT_LIST |\
  HOEDOWN_FT_QUOTE_BLOCK |\
  HOEDOWN_FT_HTML_BLOCK |\
\
  HOEDOWN_FT_ESCAPE |\
  HOEDOWN_FT_HARD_LINEBREAK |\
  HOEDOWN_FT_LINEBREAK |\
  HOEDOWN_FT_URI_AUTOLINK |\
  HOEDOWN_FT_EMAIL_AUTOLINK |\
  HOEDOWN_FT_HTML |\
  HOEDOWN_FT_ENTITY |\
  HOEDOWN_FT_CODE_SPAN |\
  HOEDOWN_FT_EMPHASIS |\
  HOEDOWN_FT_LINK |\
\
  HOEDOWN_FT_PREPROCESS |\
\
  HOEDOWN_FT_LINK_IMAGE |\
0)

#define HOEDOWN_FT_MARKDOWN (\
  HOEDOWN_FT_INDENTED_CODE_BLOCK |\
  HOEDOWN_FT_HORIZONTAL_RULE |\
  HOEDOWN_FT_ATX_HEADER |\
  HOEDOWN_FT_SETEXT_HEADER |\
  HOEDOWN_FT_LIST |\
  HOEDOWN_FT_QUOTE_BLOCK |\
  HOEDOWN_FT_HTML_BLOCK |\
\
  HOEDOWN_FT_ESCAPE |\
  HOEDOWN_FT_LINEBREAK |\
  HOEDOWN_FT_URI_AUTOLINK |\
  HOEDOWN_FT_EMAIL_AUTOLINK |\
  HOEDOWN_FT_HTML |\
  HOEDOWN_FT_ENTITY |\
  HOEDOWN_FT_CODE_SPAN |\
  HOEDOWN_FT_EMPHASIS |\
  HOEDOWN_FT_LINK |\
\
  HOEDOWN_FT_PREPROCESS |\
\
  HOEDOWN_FT_LINK_IMAGE |\
  HOEDOWN_FT_INTRA_EMPHASIS |\
0)


/*********
 * TYPES *
 *********/

typedef struct hoedown_document hoedown_document;

typedef struct hoedown_internal hoedown_internal;

typedef struct hoedown_renderer_data {
  void *opaque;
  void *output;
  hoedown_internal *doc;
} hoedown_renderer_data;

typedef struct hoedown_renderer {
  void *opaque;

  /* Block constructs */
  void (*paragraph)(void *target, void *content, int is_tight, const hoedown_renderer_data *data);
  void (*indented_code_block)(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data);
  void (*fenced_code_block)(void *target, const hoedown_buffer *code, const hoedown_buffer *info, const hoedown_renderer_data *data);
  void (*horizontal_rule)(void *target, const hoedown_renderer_data *data);
  void (*atx_header)(void *target, void *content, size_t level, const hoedown_renderer_data *data);
  void (*setext_header)(void *target, void *content, int is_double, const hoedown_renderer_data *data);
  void (*list)(void *target, void *content, int is_ordered, int is_tight, int start, const hoedown_renderer_data *data);
  void (*list_item)(void *target, void *content, int is_ordered, int is_tight, const hoedown_renderer_data *data);
  void (*quote_block)(void *target, void *content, const hoedown_renderer_data *data);
  void (*html_block)(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data);

  /* Inline constructs */
  void (*string)(void *target, const hoedown_buffer *text, const hoedown_renderer_data *data);
  void (*escape)(void *target, uint8_t character, const hoedown_renderer_data *data);
  void (*hard_linebreak)(void *target, const hoedown_renderer_data *data);
  void (*linebreak)(void *target, const hoedown_renderer_data *data);
  void (*uri_autolink)(void *target, const hoedown_buffer *uri, const hoedown_renderer_data *data);
  void (*email_autolink)(void *target, const hoedown_buffer *email, const hoedown_renderer_data *data);
  void (*html)(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data);
  void (*entity)(void *target, const hoedown_buffer *character, const hoedown_renderer_data *data);
  void (*code_span)(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data);
  void (*emphasis)(void *target, void *content, size_t level, const hoedown_renderer_data *data);
  void (*link)(void *target, void *content, const hoedown_buffer *dest, const hoedown_buffer *title, int is_image, const hoedown_renderer_data *data);

  /* Global callbacks */
  void *(*object_get)(int is_inline, const hoedown_renderer_data *data);
  void (*object_merge)(void *target, void *content, int is_inline, const hoedown_renderer_data *data);
  void (*object_pop)(void *target, int is_inline, const hoedown_renderer_data *data);

  void (*render_start)(void *output, int is_inline, const hoedown_renderer_data *data);
  void (*render_end)(void *output, void *target, int is_inline, const hoedown_renderer_data *data);
} hoedown_renderer;


/*************
 * FUNCTIONS *
 *************/

/* hoedown_find_block_tag: lookup if an HTML tag name is a block */
const char *hoedown_find_block_tag(const char *str, unsigned int len);

/* hoedown_find_autolink_scheme: lookup if a scheme is well-known */
const char *hoedown_find_autolink_scheme(const char *str, unsigned int len);

/* hoedown_preprocess: preprocess input for markdown rendering */
void hoedown_preprocess(hoedown_buffer *ob, const uint8_t *data, size_t size);


/* hoedown_document_new: allocate a new document processor */
hoedown_document *hoedown_document_new(
  hoedown_renderer *renderer,
  hoedown_features features,
  size_t max_nesting
) __attribute__((malloc));

/* hoedown_document_render: render markdown with a document processor */
void hoedown_document_render(
  hoedown_document *doc,
  void *output,
  const uint8_t *data, size_t size,
  int is_inline
);

/* hoedown_document_free: deallocate a document processor */
void hoedown_document_free(hoedown_document *doc);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_DOCUMENT_H **/
