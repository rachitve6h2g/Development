// This program checks if a square matrix is a
// lower triangular matrix

#include "array_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isLowerTriangular(int n, int **a) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] != 0) {
        return false; // Not a low triangular matrix.
      }
    }
  }
  return true;
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

  if (isLowerTriangular(n, A)) {
    printf("\nIt is an lower triangular matrix.\n");
  } else {
    printf("\nIt is not an lower triangular matrix.\n");
  }

  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);

  return 0;
}
