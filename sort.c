#include <stdio.h>

int * sort_array(int *arr, int len) {
  int temp = 0,
      *tempx_arr = NULL,
      *tempy_arr = NULL;

  tempx_arr = arr;

  // for a given index, check to see if values at other indices
  // are larger or smaller;
  // if value at index j is larger than index i, swap them,
  // and keep going until all indices are sorted

  for (tempx_arr = arr; (tempx_arr - arr) < len; tempx_arr++) {
    for (tempy_arr = arr; (tempy_arr - arr) < len; tempy_arr++) {
      if (*tempy_arr > *tempx_arr) {
        temp = *tempy_arr;
        *tempy_arr = *tempx_arr;
        *tempx_arr = temp;
      } 
    }
  }
  return arr;
}
