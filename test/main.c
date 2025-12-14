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
  if (*head == NULL) {
    *head = n;
    return;
  }

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
  Node *cur = *list;
  while (cur) {
    printf("%d\n", cur->data);
    cur = cur->next;
  }
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

  removeNthNode(&root, 5);
  removeNthNode(&root, 1);
  print_list(&root);

  free_link_list(&root);

  return EXIT_SUCCESS;
}
