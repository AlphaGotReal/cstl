#include <assert.h>
#include "list.h"

struct list *new_list(size_t n, void **values) {
  struct list *l = new_ptr(struct list);
  l->size = (size_t) 0;

  for (size_t t = 0; t < n; ++t) {
    push_back(l, values[t]);
  }

  return l;
}

void push_front(struct list *l, void *v) {
  struct listnode *node = new_ptr(struct listnode);
  node->value = v;
  node->next = l->head;
  node->prev = NULL;

  if (l->head != NULL) { l->head->prev = node; }
  else { l->tail = node; }
  
  l->head = node;
  ++(l->size);
}

void push_back(struct list *l, void *v) {
  struct listnode *node = new_ptr(struct listnode);
  node->value = v;
  node->next = NULL;
  node->prev = l->tail;

  if (l->tail != NULL) { l->tail->next = node; }
  else { l->head = node; }

  l->tail = node;
  ++(l->size);
}

void *front(struct list *l) {
  assert(l != NULL && "nullptr sent in front");  
  if (l->head == NULL) { return NULL; }
  return l->head->value;
}

void *back(struct list *l) {
  assert(l != NULL && "nullptr sent in back");  
  if (l->tail == NULL) { return NULL; }
  return l->tail->value;
}

void *pop_front(struct list *l) {
  assert(l != NULL && "nullptr sent in pop_front");  
  if (l->head == NULL) return NULL;

  void *v = l->head->value;
  l->head = l->head->next;
  if (l->head != NULL) { l->head->prev = NULL; }
  --(l->size);
  return v;
}

void *pop_back(struct list *l) {
  assert(l != NULL && "nullptr sent in pop_back");  
  if (l->tail == NULL) return NULL;

  void *v = l->tail->value;
  l->tail = l->tail->prev;
  if (l->tail != NULL) { l->tail->next = NULL; }
  --(l->size);
  return v;
}
