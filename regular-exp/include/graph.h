#pragma once
#include "link_list.h"
#include <cinttypes>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  node *head;
} adj_list;

typedef struct {

  int v;
  adj_list *adj;

} graph;

graph *create_graph(int no_of_vertices) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->v = no_of_vertices;
  g->adj = (adj_list *)malloc(sizeof(adj_list) * no_of_vertices);

  // adj , list of vertices ,which contains list of edges
  for (int i = 0; i < no_of_vertices; i++) {
    // create a list and insert into
    g->adj[i].head = NULL;
  }
  return g;
}

void add_edge(graph *g, int v, int w) {

  append(&g->adj[v].head, w);
  append(&g->adj[w].head, v);
}

void print_graph(graph *g) {
  for (int i = 0; i < g->v; i++) {

    node *temp = g->adj[i].head;

    while (temp != NULL) {
      printf("&d --> ", temp->data);
      temp = temp->next;
    }
    printf("NULL \n");
  }
}

void free_graph(graph *g) {
  for (int i = 0; i < g->v; i++) {
    node *temp = g->adj[i].head;

    while (temp != NULL) {
      node *c = temp;
      free(c);
      temp = temp->next;
    }
    free(temp);
  }
}
