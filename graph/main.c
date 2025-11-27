#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

///
/// set of vertices
/// ajd list of vertices

typedef struct adj {
  int data;
  struct adj *next;
} adj;

typedef struct {
  int vertices;
  adj **adj;
} graph;

graph *create_graph(int v) {
  graph *G = (graph *)malloc(sizeof(graph));
  G->adj = calloc(v, sizeof(adj *));
  G->vertices = v;

  for (int i = 0; i < v; i++) {
    G->adj[i] = NULL;
  }
  return G;
}
void print_graph(graph *g) {
  int v = g->vertices;
  for (int i = 0; i < v; i++) {
    printf("[%d]-- ", i);
    adj *a = g->adj[i];
    while (a != NULL) {
      printf("%d\n", a->data);
      a = a->next;
    }
    printf("\n");
  }
}

void free_graph(graph *G) {
  for (int i = 0; i < G->vertices; i++) {
    adj *a = G->adj[i];
    while (a != NULL) {
      adj *temp = a->next;
      free(a);
      a = temp;
    }
  }
  free(G->adj);
  free(G);
}

void add_directed_edge(graph *g, int v, int w) {

  adj *nn = (adj *)malloc(sizeof(adj));
  nn->data = w;
  nn->next = NULL;
  if (g->adj[v] == NULL) {
    g->adj[v] = nn;
    return;
  }

  adj *t = g->adj[v];
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = nn;
}
void rdfs(graph *g, int v, bool visited[]) {

  visited[v] = true;
  printf("visited %d ", v);

  adj *a = g->adj[v];
  while (a != NULL) {
    if (visited[a->data] == false) {
      rdfs(g, a->data, visited);
    }
    a = a->next;
  }
}

void dfs(graph *g, int s) {
  bool visited[g->vertices];
  for (int i = 0; i < g->vertices; i++)
    visited[i] = false;
  rdfs(g, s, visited);
}

int main() {
  graph *g = create_graph(5);
  add_directed_edge(g, 0, 1);
  add_directed_edge(g, 1, 2);
  add_directed_edge(g, 2, 3);
  add_directed_edge(g, 3, 4);

  dfs(g, 0);
  // print_graph(g);
  free_graph(g);
  return 0;
}
