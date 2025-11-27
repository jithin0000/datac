#include "../include/link_list.h"
#include <stdio.h>

#include <stdlib.h>
int main() {
  node *header = create_node(0);

  for (int i = 0; i < 5; i++) {
    append(&header, i);
  }

  node *t = header;
  while (t->next != NULL) {
    printf("Header value is %d \n", t->data);
    t = t->next;
  }

  free_node(header);
  return 0;
}
