#include <stdio.h>
#include <stdlib.h>

#include "cstl.h"

void display_list(struct list *l) {
  for (struct listnode *curr = l->head;
      curr != NULL; 
      curr = curr->next) {
    printf("%d ", *((int *) curr->value));
  }printf("\n");
}

int main() {

  struct list *l = new_list(0, NULL);
  int t[10] = {4, 5, 6, 7, 8, 9};

  push_back(l, &t[0]);
  push_back(l, &t[1]);
  push_back(l, &t[2]);
  push_front(l, &t[3]);

  pop_back(l);

  display_list(l);
  
  return 0;
}
