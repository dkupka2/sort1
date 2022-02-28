#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defs.h"
#include "func.h"
#include "sort.h"

int main(void) {
  srand(time(NULL));

  FILE *fp;

  int *arr = NULL,
      arr_len;

  if (NULL == (arr = malloc((arr_len + 1) * sizeof(int)))) {
    printf("Unable to allocate memory!\n");
    return -1;
  }

  if (NULL == (fp = fopen(FILE_OUT, "w+"))) {
    printf("Unable to open file!\n");
    return -2;
  }

  printf("Enter desired array length (1-32767): ");
  scanf("%d", &arr_len);

  if (arr_len < 1 || arr_len > 32767) {
    printf("Invalid entry, defaulting to 10...\n");
    arr_len = 10;
  }

  // Generate randomized numbers to populate array
  arr = randomize_array(arr, arr_len);

  // Print randomized array

  printf("Randomized array:\n");
  print_array(arr, arr_len);

  if (fp != NULL) { 
    fprintf(fp, "Randomized array:\n");
    fprint_array(fp, arr, arr_len);
  }

  // Sort numbers in array
  arr = sort_array(arr, arr_len);

  // Print sorted array
  printf("\n\nSorted array:\n");
  print_array(arr, arr_len);

  if (fp != NULL) {
    fprintf(fp, "Sorted Array:\n");
    fprint_array(fp, arr, arr_len);
  }

  fclose(fp);
  free(arr);

  return 0;
}
