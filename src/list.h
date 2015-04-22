/* list.h - self-growing array of objects */

#ifndef HOEDOWN_LIST_H
#define HOEDOWN_LIST_H

#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif


/*********
 * TYPES *
 *********/

typedef struct hoedown_list {
  void *data;
  size_t size;
  size_t asize;
  size_t unit;
} hoedown_list;


/*************
 * FUNCTIONS *
 *************/

/* hoedown_list_init: initialize a new list of objects */
void hoedown_list_init(
  hoedown_list *list,
  size_t unit,
  size_t initial_size
);

/* hoedown_list_get: get internal (temporary) pointer to an object */
void *hoedown_list_get(hoedown_list *list, size_t idx);

/* hoedown_list_grow: allocate space for a number of objects */
void hoedown_list_grow(hoedown_list *list, size_t asize);

/* hoedown_list_put: append objects to the list (FIXME: use!) */
void *hoedown_list_put(hoedown_list *list, const void *data, size_t size);

/* hoedown_list_puti: append a single object to the list */
void *hoedown_list_puti(hoedown_list *list, const void *data);

/* hoedown_list_pop: remove the last element of the list */
void *hoedown_list_pop(hoedown_list *list, void *data);

/* hoedown_list_uninit: uninitialize a list of objects */
void hoedown_list_uninit(hoedown_list *list);


/* HOEDOWN_LIGET: Optimized hoedown_list_get of an item */
#define HOEDOWN_LIGET(list, idx, type) \
  ( ((type*)((list)->data)) + idx )


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_LIST_H **/
