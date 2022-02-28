#include <stdio.h>
#include <stdlib.h>

int * randomize_array(int *arr, int len) {
  int *temp = NULL;

  temp = arr;

  while ((temp - arr) < len) {
    *temp = (rand() % 100 / 10) + 1;
    temp++;
  }
  return arr;
}

void print_array(int *arr, int len) {
  int *temp = NULL;

  temp = arr;

  while ((temp - arr) < len) {
    printf("%3d", *temp);
    temp++;
  }
  printf("\n");
}

void fprint_array(FILE * fp, int *arr, int len) {
 int *temp = NULL;

  temp = arr;

  while ((temp - arr) < len) {
    fprintf(fp, "%3d", *temp);
    temp++;
  }

  fprintf(fp, "\n");

}
