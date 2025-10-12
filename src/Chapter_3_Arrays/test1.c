// Array traversal using pointers
#include "array_utils.h"
#include <stdio.h>

int main() {
  int *y, *end; // A pointer to traverse the array.
  int size;
  printf("Enter the size of the 1D array: ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int arr[size]; // create a 1D array
  end = arr + size;
  takeArray(arr, size);
  for (y = arr; y < end; y++) {
    printf("elment stored in array are as follows: %d\n", *y);
  }
  printf("\n");
  return 0;
}
