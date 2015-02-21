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
  if (pool->size > 0)
    return pool->item[--pool->size];

  /* Allocate new item; grow pool */
  pool->isize++;
  if (pool->asize < pool->isize)
    pool->item = hoedown_realloc(pool->item, sizeof(void *) * (pool->asize *= 2));
  return pool->new_function(pool->opaque);
}

void hoedown_pool_pop(hoedown_pool *pool, void *item) {
  assert(pool->size < pool->isize);
  pool->item[pool->size++] = item;
}

void hoedown_pool_detach(hoedown_pool *pool, void *item) {
  assert(pool->size < pool->isize);
  pool->isize--;
}

void hoedown_pool_uninit(hoedown_pool *pool) {
  assert(pool->size == pool->isize);
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
