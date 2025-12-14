#ifndef ARRAY_H
#define ARRAY_H

#define DEFAULT_CAPACITY 10

typedef struct {
  int capacity;
  int size;
  int *data;
} array;

array *create_array(int c);
int resize(array *a);
void push_to_array(array *a, int item);
void get_from_array(array *a, int index);
void delete_from_array(array *a, int index);
void free_array(array *a);

#endif // !ARRAY_H
