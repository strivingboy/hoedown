#include "pool.h"

#include <assert.h>

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)


void hoedown_pool_init(
  hoedown_pool *pool,
  size_t initial_size,
  void *(*new_function)(void *opaque),
  void (*free_function)(void *item, void *opaque),
  void *opaque
) {
  if (!initial_size) initial_size = 8;

  pool->item = hoedown_malloc(sizeof(void *) * initial_size);
  pool->size = pool->isize = 0;
  pool->asize = initial_size;

  pool->new_function = new_function;
  pool->free_function = free_function;
  pool->opaque = opaque;
}


void *hoedown_pool_get(hoedown_pool *pool) {
  if (unlikely(pool->size >= pool->isize)) {
    /* Make sure there's space allocated */
    if (unlikely(pool->isize >= pool->asize)) {
      pool->asize *= 2;
      pool->item = hoedown_realloc(pool->item, sizeof(void *) * pool->asize);
    }

    /* Initialize a new object */
    pool->item[pool->isize++] = pool->new_function(pool->opaque);
  }
  return pool->item[pool->size++];
}

void hoedown_pool_pop(hoedown_pool *pool, void *item) {
  assert(pool->size > 0);
  pool->size--;
  assert(pool->item[pool->size] == item);
}

void hoedown_pool_detach(hoedown_pool *pool, void *item) {
  hoedown_pool_pop(pool, item);

  if (likely(pool->isize-1 > pool->size))
    pool->item[pool->size] = pool->item[pool->isize-1];

  pool->isize--;
}

void hoedown_pool_uninit(hoedown_pool *pool) {
  for (size_t i = 0; i < pool->isize; i++)
    pool->free_function(pool->item[i], pool->opaque);

  free(pool->item);
}


/* Pool of hoedown_buffer objects */

static void *buffer_new(void *opaque) {
  return hoedown_buffer_new((size_t)opaque);
}
static void buffer_free(void *item, void *opaque) {
  hoedown_buffer_free(item);
}

void hoedown_buffer_pool_init(hoedown_pool *pool, size_t initial_size, size_t unit) {
  hoedown_pool_init(pool, initial_size, buffer_new, buffer_free, (void *)unit);
}
