#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#define new_ptr(x) (x *) malloc(sizeof(x))

struct listnode {
  void *value;
  struct listnode *next;
  struct listnode *prev;
};

struct list {
  size_t size;
  struct listnode *head;
  struct listnode *tail;
};

struct list *new_list(size_t /* n */, void ** /* values */);

void list_push_front(struct list * /* l */, void * /* v */);
void list_push_back(struct list * /* l */, void * /* v */);

void *list_front(struct list * /* l */);
void *list_back(struct list * /* l */);

void *list_pop_front(struct list * /* l */);
void *list_pop_back(struct list * /* l */);

#endif
