#include "html.h"

#include "escape.h"

#include <string.h>
#include <assert.h>

typedef struct renderer_state {
  hoedown_pool buffers;
} renderer_state;

static void *object_get(int is_inline, const hoedown_renderer_data *data) {
  renderer_state *state = data->opaque;
  hoedown_buffer *ob = hoedown_pool_get(&state->buffers);
  ob->size = 0;
  return ob;
}

static void object_merge(void *target, void *content_, int is_inline, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;
  hoedown_buffer_put(ob, content->data, content->size);
}

static void object_pop(void *target, int is_inline, const hoedown_renderer_data *data) {
  renderer_state *state = data->opaque;
  hoedown_pool_pop(&state->buffers, target);
}

static void render_start(int is_inline, const hoedown_renderer_data *data) {
}

static void *render_end(void *target, int is_inline, const hoedown_renderer_data *data) {
  renderer_state *state = data->opaque;
  hoedown_pool_detach(&state->buffers, target);
  assert(state->buffers.size == 0);
  return target;
}


// BLOCK CONSTRUCTS

static void rndr_paragraph(void *target, void *content_, int is_tight, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  if (is_tight) {
    hoedown_buffer_put(ob, content->data, content->size);
    hoedown_buffer_putc(ob, '\n');
  } else {
    HOEDOWN_BUFPUTSL(ob, "<p>");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</p>\n");
  }
}

static void rndr_indented_code_block(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<pre><code>");
  hoedown_escape_html(ob, code->data, code->size);
  HOEDOWN_BUFPUTSL(ob, "</code></pre>\n");
}

static void rndr_fenced_code_block(void *target, const hoedown_buffer *code, const hoedown_buffer *info, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;
  HOEDOWN_BUFPUTSL(ob, "<pre><code");

  if (info) {
    size_t first_word = 0;
    while (first_word < info->size && info->data[first_word] != ' ') first_word++;

    HOEDOWN_BUFPUTSL(ob, " class=\"language-");
    hoedown_escape_html(ob, info->data, first_word);
    hoedown_buffer_putc(ob, '"');
  }

  hoedown_buffer_putc(ob, '>');
  hoedown_escape_html(ob, code->data, code->size);
  HOEDOWN_BUFPUTSL(ob, "</code></pre>\n");
}

static void rndr_horizontal_rule(void *target, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<hr />\n");
}

static void rndr_atx_header(void *target, void *content_, size_t level, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  hoedown_buffer_printf(ob, "<h%lu>", level);
  hoedown_buffer_put(ob, content->data, content->size);
  hoedown_buffer_printf(ob, "</h%lu>\n", level);
}

static void rndr_setext_header(void *target, void *content_, int is_double, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  hoedown_buffer_put(ob, (uint8_t *)(is_double ? "<h1>" : "<h2>"), 4);
  hoedown_buffer_put(ob, content->data, content->size);
  hoedown_buffer_put(ob, (uint8_t *)(is_double ? "</h1>\n" : "</h2>\n"), 6);
}

static void rndr_list(void *target, void *content_, int is_ordered, int is_tight, int start, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  hoedown_buffer_put(ob, (uint8_t *)(is_ordered ? "<ol" : "<ul"), 3);
  if (start && start != 1) hoedown_buffer_printf(ob, " start=\"%d\"", start);
  HOEDOWN_BUFPUTSL(ob, ">\n");

  hoedown_buffer_put(ob, content->data, content->size);
  hoedown_buffer_put(ob, (uint8_t *)(is_ordered ? "</ol>\n" : "</ul>\n"), 6);
}

static void rndr_list_item(void *target, void *content_, int is_ordered, int is_tight, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  HOEDOWN_BUFPUTSL(ob, "<li>");
  if (!is_tight) hoedown_buffer_putc(ob, '\n');

  hoedown_buffer_put(ob, content->data, content->size);
  if (is_tight && ob->data[ob->size-1] == '\n') ob->size--;

  HOEDOWN_BUFPUTSL(ob, "</li>\n");
}

static void rndr_quote_block(void *target, void *content_, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  HOEDOWN_BUFPUTSL(ob, "<blockquote>\n");
  hoedown_buffer_put(ob, content->data, content->size);
  HOEDOWN_BUFPUTSL(ob, "</blockquote>\n");
}

static void rndr_html_block(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  hoedown_buffer_put(ob, html->data, html->size);
}



// INLINE CONSTRUCTS

static void rndr_string(void *target, const hoedown_buffer *text, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  hoedown_escape_html(ob, text->data, text->size);
}

static void rndr_escape(void *target, uint8_t character, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  hoedown_escape_html(ob, &character, 1);
}

// hard_linebreak is set to rndr_linebreak

static void rndr_linebreak(void *target, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<br />\n");
}

static void rndr_uri_autolink(void *target, const hoedown_buffer *uri, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<a href=\"");
  hoedown_escape_href(ob, uri->data, uri->size);
  HOEDOWN_BUFPUTSL(ob, "\">");
  hoedown_escape_html(ob, uri->data, uri->size);
  HOEDOWN_BUFPUTSL(ob, "</a>");
}

static void rndr_email_autolink(void *target, const hoedown_buffer *email, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<a href=\"mailto:");
  hoedown_escape_href(ob, email->data, email->size);
  HOEDOWN_BUFPUTSL(ob, "\">");
  hoedown_escape_html(ob, email->data, email->size);
  HOEDOWN_BUFPUTSL(ob, "</a>");
}

static void rndr_html(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  hoedown_buffer_put(ob, html->data, html->size);
}

static void rndr_entity(void *target, const hoedown_buffer *character, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  hoedown_escape_character(ob, character->data, character->size);
}

static void rndr_code_span(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target;

  HOEDOWN_BUFPUTSL(ob, "<code>");
  hoedown_escape_html(ob, code->data, code->size);
  HOEDOWN_BUFPUTSL(ob, "</code>");
}

static void rndr_emphasis(void *target, void *content_, size_t level, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  if (level == 3) {
    HOEDOWN_BUFPUTSL(ob, "<strong><em>");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</em></strong>");
  } else if (level == 2) {
    HOEDOWN_BUFPUTSL(ob, "<strong>");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</strong>");
  } else {
    HOEDOWN_BUFPUTSL(ob, "<em>");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</em>");
  }

}

static void rndr_link(void *target, void *content_, const hoedown_buffer *dest, const hoedown_buffer *title, int is_image, const hoedown_renderer_data *data) {
  hoedown_buffer *ob = target, *content = content_;

  if (is_image) {
    HOEDOWN_BUFPUTSL(ob, "<img src=\"");
    hoedown_escape_href(ob, dest->data, dest->size);
    HOEDOWN_BUFPUTSL(ob, "\" alt=\"");
    hoedown_escape_html(ob, content->data, content->size);
    hoedown_buffer_putc(ob, '"');

    if (title) {
      HOEDOWN_BUFPUTSL(ob, " title=\"");
      hoedown_escape_html(ob, title->data, title->size);
      hoedown_buffer_putc(ob, '"');
    }

    HOEDOWN_BUFPUTSL(ob, " />");
  } else {
    HOEDOWN_BUFPUTSL(ob, "<a href=\"");
    hoedown_escape_href(ob, dest->data, dest->size);
    hoedown_buffer_putc(ob, '"');

    if (title) {
      HOEDOWN_BUFPUTSL(ob, " title=\"");
      hoedown_escape_html(ob, title->data, title->size);
      hoedown_buffer_putc(ob, '"');
    }

    hoedown_buffer_putc(ob, '>');
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</a>");
  }
}



// RENDERER INITIALIZATION

hoedown_renderer *hoedown_html_renderer_new() {
  static const hoedown_renderer temp = {
    NULL,

    rndr_paragraph,
    rndr_indented_code_block,
    rndr_fenced_code_block,
    rndr_horizontal_rule,
    rndr_atx_header,
    rndr_setext_header,
    rndr_list,
    rndr_list_item,
    rndr_quote_block,
    rndr_html_block,

    rndr_string,
    rndr_escape,
    rndr_linebreak,
    rndr_linebreak,
    rndr_uri_autolink,
    rndr_email_autolink,
    rndr_html,
    rndr_entity,
    rndr_code_span,
    rndr_emphasis,
    rndr_link,

    object_get,
    object_merge,
    object_pop,

    render_start,
    render_end,
  };

  hoedown_renderer *rndr = hoedown_malloc(sizeof(hoedown_renderer));
  renderer_state *state = hoedown_malloc(sizeof(renderer_state));

  memcpy(rndr, &temp, sizeof(hoedown_renderer));
  rndr->opaque = state;

  hoedown_buffer_pool_init(&state->buffers, 16, 16);

  return rndr;
}

void hoedown_html_renderer_free(hoedown_renderer *rndr) {
  if (!rndr) return;

  renderer_state *state = rndr->opaque;
  hoedown_pool_uninit(&state->buffers);
  free(state);

  free(rndr);
}
