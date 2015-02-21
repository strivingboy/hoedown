/* html.h - HTML renderer and utilities */

#ifndef HOEDOWN_HTML_H
#define HOEDOWN_HTML_H

#include "document.h"
#include "buffer.h"
#include "pool.h"

#ifdef __cplusplus
extern "C" {
#endif


/*********
 * TYPES *
 *********/

typedef struct hoedown_html_renderer_state {
  void *opaque;
  hoedown_pool buffers;
} hoedown_html_renderer_state;


/*************
 * FUNCTIONS *
 *************/

/* hoedown_html_renderer_new: allocate a new HTML renderer */
hoedown_renderer *hoedown_html_renderer_new() __attribute__((malloc));

/* hoedown_html_renderer_free: deallocate an HTML renderer */
void hoedown_html_renderer_free(hoedown_renderer *rndr);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_HTML_H **/
