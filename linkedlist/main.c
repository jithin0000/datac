#include <assert.h>
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
// add item front of the linked list
void add_front(node **head, int v) {
  node *nn = (node *)malloc(sizeof(node));
  nn->data = v;
  nn->next = *head;
  *head = nn;
}

// add item end of the linkd list
void add_last(node **head, int v) {
  node *n = (node *)malloc(sizeof(node));
  n->data = v;
  n->next = NULL;
  node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = n;
};

// get front
int front(node *head) {
  assert(head != NULL);
  return head->data;
}

int back(node *head) {
  assert(head != NULL);
  while (head->next != NULL)
    head = head->next;
  return head->data;
}

// insert before a node
// insert after node

void free_link_list(node *head) {
  while (head != NULL) {
    node *temp = head->next;
    free(head);
    head = temp;
  }
}

int main() {

  node *head = create_node();

  for (int i = 0; i < 5; i++) {
    add_front(&head, i);
  }
  add_last(&head, 100);

  printf("Front: %d \n", front(head));
  printf("Back: %d \n", back(head));

  free_link_list(head);
  return 0;
}
