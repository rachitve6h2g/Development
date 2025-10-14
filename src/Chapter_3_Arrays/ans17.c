// This program takes a 2D matrix and
// calculates the sum of elements below the main diagonal

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;
  printf("Enter the size of the 2D matrix = ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Invalid input!\n");
    return 1;
  }

  int **A = create2DArr(n, n); // Create a 2D array.
  take2DArray(A, n, n);        // Input a 2D array.
  print2DMatrix(A, n, n);      // Output the 2D array in matrix
  // form.

  int sum = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      sum += A[i][j];
    }
  }

  for (int i = 0; i < n; i++)
    free(A[i]);
  free(A);

  printf("\nThe sum of the elements below the main diagonal = %d\n", sum);

  return 0;
}
