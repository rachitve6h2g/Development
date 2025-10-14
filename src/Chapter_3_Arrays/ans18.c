// This program takes a square matrix
// and checks if it's a upper triangular matrix.

#include "array_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isUpperTriangular(int n, int **a) {
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[i][j] != 0)
        return false; // Not an upper triangular matrix

  return true; // Is an upper triangular matrix
}

int main() {
  int n = 0;
  printf("Enter the size of the square of the matrix = ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int **A = create2DArr(n, n);
  take2DArray(A, n, n);
  print2DMatrix(A, n, n);

  if (isUpperTriangular(n, A)) {
    printf("\nIt is an upper triangular matrix.\n");
  } else {
    printf("\nIt is not an upper triangular matrix.\n");
  }

  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);

  return 0;
}
