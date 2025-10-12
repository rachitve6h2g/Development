// Find the sum of diagonal elements of a matrix using pointers.

#include "array_utils.h"
#include <stdio.h>

int main() {
  int rows, cols;
  printf("Enter the number of rows(cols will copy the value): ");
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  cols = rows;

  int **arr = create2DArr(rows, cols);

  // Input the array
  take2DArray(arr, rows, cols);

  // Print the array in matrix form
  print2DMatrix(arr, rows, cols);

  int sum = 0;
  for (int i = 0; i < rows; i++) {
    sum += arr[i][i];
  }

  printf("\nSum of diagonals is = %d\n", sum);

  return 0;
}
