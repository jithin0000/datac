#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node() {
  node *n = (node *)malloc(sizeof(node));
  n->data = 0;
  n->next = NULL;
  return n;
}

void add_node(node **head, int v) {
  node *nn = (node *)malloc(sizeof(node));
  nn->data = v;
  nn->next = *head;
  *head = nn;
}

void free_link_list(node *head) {
  node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {

  node *head = create_node();

  for (int i = 0; i < 5; i++) {
    add_node(&head, i);
  }

  free(head);
  return 0;
}
