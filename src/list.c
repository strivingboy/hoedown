#include "list.h"

#include <string.h>
#include <assert.h>

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)


void hoedown_list_init(
  hoedown_list *list,
  size_t unit,
  size_t initial_size
) {
  if (!initial_size) initial_size = 4;

  list->data = hoedown_calloc(initial_size, unit);
  list->size = 0;
  list->asize = initial_size;
  list->unit = unit;
}

void hoedown_list_grow(hoedown_list *list, size_t asize) {
  assert(list && list->unit);
  while (list->asize < asize) {
    list->asize *= 2;
    list->data = hoedown_realloc(list->data, list->asize*list->unit);
  }
}

void *hoedown_list_get(hoedown_list *list, size_t idx) {
  return list->data + idx*list->unit;
}

void *hoedown_list_put(hoedown_list *list, const void *data, size_t size) {
  assert(list && list->unit);
  if (unlikely(list->size + size > list->asize))
    hoedown_list_grow(list, list->size + size);

  void *ldata = list->data + list->size*list->unit;
  if (data) memcpy(ldata, data, size*list->unit);
  list->size += size;
  return ldata;
}

void *hoedown_list_puti(hoedown_list *list, const void *data) {
  assert(list && list->unit);
  if (unlikely(list->size >= list->asize)) {
    list->asize *= 2;
    list->data = hoedown_realloc(list->data, list->asize * list->unit);
  }

  void *ldata = list->data + list->size*list->unit;
  if (data) memcpy(ldata, data, list->unit);
  list->size++;
  return ldata;
}

void *hoedown_list_pop(hoedown_list *list, void *data) {
  assert(list && list->unit);
  list->size--;
  void *ldata = list->data + list->size*list->unit;
  if (data) memcpy(data, ldata, list->unit);
  return ldata;
}

void hoedown_list_uninit(hoedown_list *list) {
  assert(list && list->unit);
  free(list->data);
}
