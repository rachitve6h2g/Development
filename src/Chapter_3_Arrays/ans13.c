// This program is to exchange the secondMax element
// and the secondMin element in a single-dimensional
// integer array.

#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  printf("Enter the size of the array: ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int *arr = malloc(size * sizeof(int));

  // Take the elements of the array
  printf("\nEnter the elements of the array:\n");
  takeArray(arr, size);

  // Print the originial array
  printf("\nOriginal Array:\n");
  printArray(arr, size);

  // Find the secondMax of the array.
  int posSecondMax = 0;
  int secondMax = secondMaxElement(arr, size, &posSecondMax);

  // Find the secondMin of the array
  int posSecondMin = 0;
  int secondMin = secondMinElement(arr, size, &posSecondMin);

  // Swap these two
  swap(&arr[posSecondMax], &arr[posSecondMin]);

  printf("\nArray after swapping the secondMax(%d) and secondMin(%d).\n",
         secondMax, secondMin);
  printArray(arr, size);

  free(arr);

  return 0;
}
