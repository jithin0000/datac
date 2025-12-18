#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random(int max) {
  int min = 1;
  return (rand() % (max - min + 1)) + min;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  FILE *fptr;

  fptr = fopen("100000.txt", "w");
  if (fptr == NULL) {
    printf("File not found ");
    exit(1);
  }

  int i = 0;
  fprintf(fptr, "%d \n", generate_random(100000));
  while (i < 100000) {
    i++;
  }

  fclose(fptr);

  return EXIT_SUCCESS;
}
