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

/* FEATURE FLAGS */

/* Block constructs */
#define HOEDOWN_FT_DIRECTIVE (1l << 0)
#define HOEDOWN_FT_INDENTED_CODE_BLOCK (1l << 1)
#define HOEDOWN_FT_FENCED_CODE_BLOCK (1l << 2)
#define HOEDOWN_FT_HORIZONTAL_RULE (1l << 3)
#define HOEDOWN_FT_ATX_HEADER (1l << 4)
#define HOEDOWN_FT_SETEXT_HEADER (1l << 5)
#define HOEDOWN_FT_LIST (1l << 8)
#define HOEDOWN_FT_QUOTE_BLOCK (1l << 31)
#define HOEDOWN_FT_HTML_BLOCK (1l << 6)
#define HOEDOWN_FT_TABLE (1l << 7)
#define HOEDOWN_FT_FOOTNOTE (1l << 27)

/* Inline constructs */
#define HOEDOWN_FT_ROLE (1l << 9)
#define HOEDOWN_FT_ESCAPE (1l << 10)
#define HOEDOWN_FT_LINEBREAK (1l << 12)
#define HOEDOWN_FT_URI_AUTOLINK (1l << 14)
#define HOEDOWN_FT_EMAIL_AUTOLINK (1l << 15)
#define HOEDOWN_FT_HTML (1l << 16)
#define HOEDOWN_FT_ENTITY (1l << 17)
#define HOEDOWN_FT_CODE (1l << 18)
#define HOEDOWN_FT_EMPHASIS (1l << 19)
#define HOEDOWN_FT_LINK (1l << 20)
#define HOEDOWN_FT_MATH (1l << 22)
#define HOEDOWN_FT_SUPERSCRIPT (1l << 23)
#define HOEDOWN_FT_QUOTE (1l << 24)
#define HOEDOWN_FT_STRIKETHROUGH (1l << 25)
#define HOEDOWN_FT_HIGHLIGHT (1l << 26)
#define HOEDOWN_FT_SIDENOTE (1l << 32)
#define HOEDOWN_FT_EMOJI (1l << 33)
#define HOEDOWN_FT_TYPOGRAPHY (1l << 34)

/* Other features */
#define HOEDOWN_FT_PREPROCESS (1l << 62)

/* Flags */
#define HOEDOWN_FT_LINEBREAK_HARD (1l << 11)
#define HOEDOWN_FT_LINEBREAK_SOFT (1l << 13)
#define HOEDOWN_FT_LINK_IMAGE (1l << 21)
#define HOEDOWN_FT_INTRA_EMPHASIS (1l << 29)
#define HOEDOWN_FT_MATH_EXPLICIT (1l << 30)


/* FEATURE GROUPS */

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
  HOEDOWN_FT_FOOTNOTE |\
0)

#define HOEDOWN_FT_INLINE (\
  HOEDOWN_FT_ROLE |\
  HOEDOWN_FT_ESCAPE |\
  HOEDOWN_FT_LINEBREAK |\
  HOEDOWN_FT_URI_AUTOLINK |\
  HOEDOWN_FT_EMAIL_AUTOLINK |\
  HOEDOWN_FT_HTML |\
  HOEDOWN_FT_ENTITY |\
  HOEDOWN_FT_CODE |\
  HOEDOWN_FT_EMPHASIS |\
  HOEDOWN_FT_LINK |\
  HOEDOWN_FT_MATH |\
  HOEDOWN_FT_SUPERSCRIPT |\
  HOEDOWN_FT_QUOTE |\
  HOEDOWN_FT_STRIKETHROUGH |\
  HOEDOWN_FT_HIGHLIGHT |\
  HOEDOWN_FT_SIDENOTE |\
  HOEDOWN_FT_EMOJI |\
  HOEDOWN_FT_TYPOGRAPHY |\
0)

#define HOEDOWN_FT_OTHER (\
  HOEDOWN_FT_PREPROCESS |\
0)

#define HOEDOWN_FT_FLAGS (\
  HOEDOWN_FT_LINEBREAK_HARD |\
  HOEDOWN_FT_LINEBREAK_SOFT |\
  HOEDOWN_FT_LINK_IMAGE |\
  HOEDOWN_FT_INTRA_EMPHASIS |\
  HOEDOWN_FT_MATH_EXPLICIT |\
0)


/* FEATURE PRESETS */

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
  HOEDOWN_FT_LINEBREAK |\
  HOEDOWN_FT_URI_AUTOLINK |\
  HOEDOWN_FT_EMAIL_AUTOLINK |\
  HOEDOWN_FT_HTML |\
  HOEDOWN_FT_ENTITY |\
  HOEDOWN_FT_CODE |\
  HOEDOWN_FT_EMPHASIS |\
  HOEDOWN_FT_LINK |\
\
  HOEDOWN_FT_PREPROCESS |\
\
  HOEDOWN_FT_LINEBREAK_HARD |\
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
  HOEDOWN_FT_CODE |\
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

typedef uint64_t hoedown_features;

typedef struct hoedown_document hoedown_document;

typedef struct hoedown_internal hoedown_internal;

typedef struct hoedown_renderer_data {
  void *opaque;
  void *request;
  hoedown_internal *doc;
} hoedown_renderer_data;

typedef struct hoedown_renderer {
  void *opaque;

  /* Block constructs */
  void (*paragraph)(void *target, void *content, int is_tight, const hoedown_renderer_data *data);
  void (*indented_code_block)(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data);
  void (*fenced_code_block)(void *target, const hoedown_buffer *code, const hoedown_buffer *info, const hoedown_renderer_data *data);
  void (*horizontal_rule)(void *target, const hoedown_renderer_data *data);
  void (*atx_header)(void *target, void *content, size_t width, const hoedown_renderer_data *data);
  void (*setext_header)(void *target, void *content, int is_double, const hoedown_renderer_data *data);
  void (*list)(void *target, void *content, int is_ordered, int is_tight, int start, const hoedown_renderer_data *data);
  void (*list_item)(void *target, void *content, int is_ordered, int is_tight, const hoedown_renderer_data *data);
  void (*quote_block)(void *target, void *content, const hoedown_renderer_data *data);
  void (*html_block)(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data);

  /* Inline constructs */
  void (*string)(void *target, const hoedown_buffer *text, const hoedown_renderer_data *data);
  void (*escape)(void *target, uint8_t character, const hoedown_renderer_data *data);
  void (*linebreak)(void *target, int is_hard, int is_soft, const hoedown_renderer_data *data);
  void (*uri_autolink)(void *target, const hoedown_buffer *uri, const hoedown_renderer_data *data);
  void (*email_autolink)(void *target, const hoedown_buffer *email, const hoedown_renderer_data *data);
  void (*html)(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data);
  void (*entity)(void *target, const hoedown_buffer *character, const hoedown_renderer_data *data);
  void (*code)(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data);
  void (*emphasis)(void *target, void *content, size_t width, uint8_t delimiter, const hoedown_renderer_data *data);
  void (*link)(void *target, void *content, const hoedown_buffer *dest, const hoedown_buffer *title, int is_image, const hoedown_renderer_data *data);
  void (*math)(void *target, const hoedown_buffer *math, int is_inline, const hoedown_renderer_data *data);
  void (*emoji)(void *target, const hoedown_buffer *name, const hoedown_renderer_data *data);
  void (*typography)(void *target, const hoedown_buffer *character, const hoedown_renderer_data *data);

  /* Global callbacks (mandatory) */
  void *(*object_get)(int is_inline, const hoedown_renderer_data *data);
  void (*object_merge)(void *target, void *content, int is_inline, const hoedown_renderer_data *data);
  void (*object_pop)(void *target, int is_inline, const hoedown_renderer_data *data);

  void (*render_start)(int is_inline, const hoedown_renderer_data *data);
  void *(*render_end)(void *target, int is_inline, const hoedown_renderer_data *data);
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
void *hoedown_document_render(
  hoedown_document *doc,
  const uint8_t *data, size_t size,
  int is_inline, void *request
);

/* hoedown_document_free: deallocate a document processor */
void hoedown_document_free(hoedown_document *doc);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_DOCUMENT_H **/
