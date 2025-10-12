// Count the number of non-zero elements
// in a two-dimensional array.

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **arr, rows, cols;

  printf("Enter the number of rows = ");
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }
  printf("Enter the number of columns = ");
  if (scanf("%d", &cols) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  printf("\n");

  arr = create2DArr(rows, cols);
  take2DArray(arr, rows, cols); // Input a 2D array.
  printf("\n");
  printf("Entered array in matrix form:\n");
  print2DMatrix(arr, rows, cols);

  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (*(*(arr + i) + j) != 0) {
        count++;
      }
    }
  }

  if (!count) {
    printf("This is a zero matrix.\n");
  } else {
    printf("The number of non-zero elements in the array is %d\n", count);
  }

  for (int i = 0; i < rows; i++)
    if (arr[i] != NULL)
      free(arr[i]);
  free(arr);

  return 0;
}
