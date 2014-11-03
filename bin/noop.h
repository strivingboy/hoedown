/* noop.h - dumb no-op renderer */

#ifndef HOEDOWN_NOOP_H
#define HOEDOWN_NOOP_H

#include "document.h"

#ifdef __cplusplus
extern "C" {
#endif


/*************
 * FUNCTIONS *
 *************/

/* hoedown_noop_renderer_new: allocate a new no-op renderer */
hoedown_renderer *hoedown_noop_renderer_new() __attribute__((malloc));

/* hoedown_noop_renderer_free: deallocate a no-op renderer */
void hoedown_noop_renderer_free(hoedown_renderer *rndr);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_NOOP_H **/
