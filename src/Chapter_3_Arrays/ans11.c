// Make a 2D array.
// Make two arrays. One will store the odd elements from the 2D array
// and the other will store the even ones.

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **A, rows, cols;
  int evenCount, oddCount;
  evenCount = oddCount = 0;

  printf("\nEnter the number of rows = ");
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  printf("\nEnter the number of columns = ");
  if (scanf("%d", &cols) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  A = create2DArr(rows, cols);

  // First take the array.
  take2DArray(A, rows, cols);
  // Print the array in matrix form
  printf("\n");
  print2DMatrix(A, rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (*(*(A + i) + j) % 2 == 0) {
        evenCount++;
      } else {
        oddCount++;
      }
    }
  }

  int *even = malloc(evenCount * sizeof(int));
  int *odd = malloc(oddCount * sizeof(int));

  if (!even || !odd) {
    fprintf(stderr, "Memory failed to allcate.\n");
    return 1;
  }

  int *x, *y;
  x = even, y = odd;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (A[i][j] % 2 == 0) {
        *x++ = A[i][j];
      } else {
        *y++ = A[i][j];
      }
    }
  }

  printf("\nEven numbers are:\n");
  printArray(even, evenCount);

  printf("\nOdd numbers are:\n");
  printArray(odd, oddCount);

  free(even);
  free(odd);
  for (int i = 0; i < rows; i++) {
    free(A[i]);
  }
  free(A);

  return 0;
}
