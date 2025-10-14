// Take a matrix and check if it's symmetric
// Hint: if A[i][j] == A[j][i] then it's symmetric

#include "array_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isSymmetric(int n, int **arr) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i][j] != arr[j][i]) {
        return false;
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

  if (isSymmetric(n, A)) {
    printf("\nIt is an symmetric matrix.\n");
  } else {
    printf("\nIt is not an symmetric matrix.\n");
  }

  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);

  return 0;
}
