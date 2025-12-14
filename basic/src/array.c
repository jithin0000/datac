#include "../include/array.h"
#include <stdlib.h>

/**
 * create array
 * user need to provide @capacity, else it would
 * initiate with default capcity
 * */
array *create_array(int capacity) {

  array *a = malloc(sizeof(array));
  if (!a) {
    return NULL;
  }

  int c = capacity <= 0 ? DEFAULT_CAPACITY : capacity;
  a->size = 0;
  a->capacity = c;

  a->data = calloc(c, sizeof(int));
  if (!a->data) {
    free(a);
    return NULL;
  }

  return a;
}

/**
 * resize array into new array
 * if its size reached half of its capacity
 */
int resize(array *a) {
  int new_capacity = 2 * a->capacity;
  int *data = realloc(a->data, new_capacity * sizeof(int));
  if (!data)
    return 0; // realloction failed

  a->data = data;
  a->capacity = new_capacity;
  return 1;
}

// void push_to_array(array *a, int item);

// void get_from_array(array *a, int index);
// void delete_from_array(array *a, int index);
// void free_array(array *a);
