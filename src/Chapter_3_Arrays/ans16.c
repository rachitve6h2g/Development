// This program takes matrix and
// prints the sum of the upper half triangle
// (triangle above the main diagonal)
// A{i}{j} where i < j

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;
  printf("Enter the size of the matrix = ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int sum = 0;
  int **A = create2DArr(n, n); // Create an array.
  take2DArray(A, n, n);        // Input a 2D array.
  print2DMatrix(A, n, n);      // Print the 2D array in matrix
  // form.

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum += A[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    free(A[i]);
  }

  free(A);

  printf("The sum of the elements above main diagonal = %d.\n", sum);
  return 0;
}
