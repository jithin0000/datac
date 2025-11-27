#include "../include/list.h"
#include <stdlib.h>

list *initiate_list(int capacity) {
  list *l = (list *)malloc(sizeof(list));
  l->size = 0;
  l->data = (int *)malloc(sizeof(int) * capacity);
  return l;
}
