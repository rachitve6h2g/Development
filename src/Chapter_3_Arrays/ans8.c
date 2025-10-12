// Write a program to add two 3x3 matrices using pointers.

#include "array_utils.h"
#include <stdio.h>

int main() {
  int **arr1, **arr2, **arr3;
  int rows, cols;
  rows = cols = 3;
  arr1 = create2DArr(rows, cols); // Taken from the user
  arr2 = create2DArr(rows, cols); // Taken from the user
  arr3 = create2DArr(rows, cols); // For the sum.

  printf("\n");
  printf("Enter the first 2D array:\n");
  take2DArray(arr1, rows, cols);
  printf("\n");
  print2DMatrix(arr1, rows, cols);

  printf("\n");
  printf("Enter the second 2D array:\n");
  take2DArray(arr2, rows, cols);
  printf("\n");
  print2DMatrix(arr2, rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      *(*(arr3 + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
    }
  }

  printf("\n");
  print2DMatrix(arr3, rows, cols);

  return 0;
}
