#include "../include/link_list.h"
#include <stdlib.h>
/*
 * create node
 */
node *create_node(int data) {
  node *N = (node *)malloc(sizeof(node));
  N->data = data;
  N->next = NULL;
  return N;
}
/**
 * append , add item end of the linked list
 **/
void append(node **ll, int v) {

  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = v;
  if (ll == NULL) {
    *ll = new_node;
    return;
  }

  node *t = *ll;
  while (t->next != NULL) {
    t = t->next;
  }

  t->next = new_node;
}

/*
 * clear linked list
 */
void free_node(node *N) {

  node *t = N;
  while (t != NULL) {
    node *next = t->next;
    free(t);
    t = next;
  }
  N = NULL;
}
