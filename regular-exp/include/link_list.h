#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data);

void append(node **ln, int v);
void prepend(node *ln, int v);
void ll_remove(node *node);
void free_node(node *node);

#endif // !LINKED_LIST_H once
