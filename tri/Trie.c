#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node **next;
} Node;

Node *create_tri(int v) {
  Node *root = (Node *)malloc(sizeof(Node));
  root->value = v;
  root->next = (Node **)calloc(26, sizeof(Node *));
  return root;
}

void free_tri(Node *root) {

  if (root == NULL)
    return;

  for (int i = 0; i < 26; i++) {
    free_tri(root->next[i]);
  }
  free(root->next);
  free(root);
}

Node *insert(Node *root, char *s, int v, int d) {

  if (root == NULL) {
    root = create_tri(v);
  }
  if (s[d] == '\0') {
    root->value = v;
    return root;
  }
  int idx = s[d] - 'a';
  root->next[idx] = insert(root->next[idx], s, v, d + 1);
  return root;
}

int main(int argc, char *argv[]) {

  printf("Hello world \n");
  Node *root = create_tri(0);
  insert(root, "cat", 1, 0);
  free_tri(root);
  return EXIT_SUCCESS;
}
