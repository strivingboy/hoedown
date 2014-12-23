/* pool.h - stack-based pool of reusable objects */

#ifndef HOEDOWN_POOL_H
#define HOEDOWN_POOL_H

#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif


/*********
 * TYPES *
 *********/

typedef struct hoedown_pool {
  void **item;
  size_t size;
  size_t isize;
  size_t asize;

  void *(*new_function)(void *opaque);
  void (*free_function)(void *item, void *opaque);
  void *opaque;
} hoedown_pool;


/*************
 * FUNCTIONS *
 *************/

/* hoedown_pool_init: initialize a new pool of objects */
void hoedown_pool_init(
  hoedown_pool *pool,
  size_t initial_size,
  void *(*new_function)(void *opaque),
  void (*free_function)(void *item, void *opaque),
  void *opaque
);

/* hoedown_pool_get: reserve and return the next object from the pool */
void *hoedown_pool_get(hoedown_pool *pool);

/* hoedown_pool_pop: unreserve the last reserved object from the pool */
void hoedown_pool_pop(hoedown_pool *pool, void *item);

/* hoedown_pool_detach: unreserve and disown the last reserved object from the pool */
void hoedown_pool_detach(hoedown_pool *pool, void *item);

/* hoedown_pool_uninit: uninitialize a pool of objects */
void hoedown_pool_uninit(hoedown_pool *pool);


/* hoedown_buffer_pool_init: convenience method to create a pool of buffers */
void hoedown_buffer_pool_init(hoedown_pool *pool, size_t initial_size, size_t unit);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_POOL_H **/
