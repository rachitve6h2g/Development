// This program takes a matrix and calculates the sum of the
// diagonal elements.
#include <stdio.h>

int main() {
  int n;
  printf("Enter the size of the matrix: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  // Declare a 2D array.
  int arr[n][n];

  // Take the array.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Enter element at [%d][%d] = ", i, j);
      if (scanf("%d", &arr[i][j]) != 1) {
        return 1;
      }
    }
  }

  // Print the array.
  printf("\n\nThe array you entered in matrix form.\n\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }

  int sum = 0; // Take The sum.

  for (int i = 0; i < n; i++) {
    sum += arr[i][i];
  }

  printf("\nThis is the sum of the diagonal elements: %3d\n", sum);

  return 0;
}
