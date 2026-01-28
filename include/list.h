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

void push_front(struct list * /* l */, void * /* v */);
void push_back(struct list * /* l */, void * /* v */);

void *front(struct list * /* l */);
void *back(struct list * /* l */);

void *pop_front(struct list * /* l */);
void *pop_back(struct list * /* l */);

#endif
