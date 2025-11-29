#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Hello world \n");

  array *a = create_array(2);

  free(a->data);
  free(a);

  return EXIT_SUCCESS;
}
