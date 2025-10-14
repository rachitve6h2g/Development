// This is a program that removes duplicates from a
// 1D array.

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  printf("Enter the size of the 1D array = ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int *arr = malloc(sizeof(int) * size);

  takeArray(arr, size);
  printf("Original array:\n");
  printArray(arr, size);

  int dup = removeDups(arr, size);
  printf("After removing duplicates.\n");
  printArray(arr, dup);

  return 0;
}
