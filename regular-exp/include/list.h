#pragma once

typedef struct {
  int *data;
  int size;
  int capacity;
} list;

list *initiate_list(int capacity);
void push_to_list(list *list, int value);
void resize(list *list);
void remove_from_list(list *list, int index);
void free_list(list *a);
