// This is actually a two sum problem
// And the answer to question number two.

// TODO: This code is better written using hash table,
// this is the brute force method.

#include "array_utils.h"
#include <stdio.h>

int main() {
  int i, j;
  int size = 0;
  printf("Enter the size of the array: ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int arr[size];
  printf("Enter the array.\n");
  takeArray(arr, size);

  printf("\nThis is the array that you entered\n");
  printArray(arr, size);

  printf("\n");

  int target = 0; // For the target number.
  printf("Enter the target = ");
  if (scanf("%d", &target) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int found = 0;
  for (i = 0; i < size - 1; i++) {
    j = i + 1;
    while (j < size) {
      if (arr[i] + arr[j] == target) {
        printf("pair found at %d, %d = %d %d\n", i, j, arr[i], arr[j]);
        found = 1;
      }
      j++;
    }
  }

  if (!found) {
    printf("Pair not found for target %d.\n", target);
  }

  return 0;
}
