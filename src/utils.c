#include "utils.h"

void *min(void *a, void *b) {
  return (*a > *b ? b : a);
}

void *max(void *a, void *b) {
  return (*a > *b ? a : b);
}

void swap(void *a, void *b) {
  void *temp = a;
  a = b;
  b = a;
}

void sort(void **begin, void **end) {
  // ig just bubble sort for now??
  for (int i = 0; i < (end - begin); ++i) {
    for (int j = 0; j < i; ++j) {
      if (*begin[i] > *begin[j]) {
        swap(begin[i], begin[j]);
      }
    }
  }
}

void reverse(void **begin, void **end) {
  for (void **f = begin, **b = end; f != b; ++f, --b) {
    swap(*f, *b);
  }
}

