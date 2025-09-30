#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  /*
  @Param num_arrays: number of input arrays
  @Param sizes: array of sizes of each input array
  @Param values: array of input arrays

  @Returns: a new array containing the count of unique elements
            followed by the unique elements in sorted order.
  */
  int total = 0;
  for (int i = 0; i < num_arrays; i++) {
    total += sizes[i];
  }

  int* all = (int*) calloc(total, sizeof(int));
  int idx = 0;

  for (int i = 0; i < num_arrays; i++) {
    for (int j = 0; j < sizes[i]; j++) {
      all[idx++] = values[i][j];
    }
  }

  mergesort(total, all);

  int* result = (int*) calloc((total + 1), sizeof(int));
  int unique_count = 0;
  for (int i = 0; i < total; i++) {
    if (i == 0 || all[i] != all[i - 1]) {
      result[unique_count + 1] = all[i];
      unique_count++;
    }
  }
  result[0] = unique_count;

  free(all);

  // Caller is responsible for freeing the returned array.
  return result;
}