#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

/**
 * create linked list
 **/
Node *create_node(int data) {

  Node *node = (Node *)malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
}

void free_link_list(Node **root) {

  Node *cur = *root;
  while (cur) {
    Node *next = cur->next;
    free(cur);
    cur = next;
  }
  *root = NULL;
}
void prepend(Node **head, int data) {
  Node *n = create_node(data);
  n->next = *head;
  *head = n;
}
void append(Node **root, int data) {
  Node *n = create_node(data);
  if (*root == NULL) {
    *root = n;
    return;
  }
  Node *t = *root;
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = n;
}

void print_list(Node **list) {
  if (*list == NULL)
    return;
  Node *cur = *list;
  printf("%d\n", cur->data);
  print_list(&cur->next);
}

bool insert_after(Node **root, int k, int v) {
  Node *c = *root;
  while (c && c->data != k)
    c = c->next;
  if (!c)
    return false;
  Node *n = create_node(v);
  n->next = c->next;
  c->next = n;
  return true;
}

bool search(Node **root, int k) {
  Node *c = *root;
  while (c && c->data != k) {
    c = c->next;
  }
  if (!c)
    return false;
  return true;
}

bool removeNthNode(Node **root, int key) {
  Node *cur = *root;
  Node *prev = NULL;
  while (cur && cur->data != key) {
    prev = cur;
    cur = cur->next;
  }
  if (!cur) {
    printf("Item not found for remove \n");
    return false;
  }
  if (prev == NULL) {
    *root = cur->next;
  } else {
    prev->next = cur->next;
  }
  free(cur);

  return true;
}

void reverse(Node **root) {
  if (root == NULL)
    return;
  Node *cur = *root;
  Node *n = create_node(cur->data);

  while (cur->next) {
    cur = cur->next;
    prepend(&n, cur->data);
  }

  free_link_list(root);
  *root = n;
}

void reverse_single(Node **root) {
  Node *prev = NULL;
  Node *cur = *root;
  Node *temp = NULL;
  while (cur->next) {
    temp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = temp;
  }
  cur->next = prev;

  *root = cur;
}

int main() {

  FILE *fptr;
  char fileName[] = "./input.txt";
  fptr = fopen(fileName, "r");

  if (fptr == NULL) {
    printf("Error failed to open file");
    exit(1);
  }

  char buffer[100];
  Node *root;

  while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    append(&root, atoi(buffer));
  }

  fclose(fptr);

  clock_t start, end;
  double cpu_time_used;
  start = clock();

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time take : %f seconds\n", cpu_time_used);

  reverse_single(&root);
  print_list(&root);

  free_link_list(&root);

  return EXIT_SUCCESS;
}
