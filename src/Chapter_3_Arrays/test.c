#include "array_utils.h"
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of the \narray you wanna create: ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int arr[size];

  takeArray(arr, size);
  printArray(arr, size);

  int sum = sumOfElements(arr, size);

  printf("Sum of the elements is: %d\n", sum);

  int max, min, secondMax, secondMin;
  max = maxElement(arr, size);
  min = minElement(arr, size);
  secondMax = secondMaxElement(arr, size);
  secondMin = secondMinElement(arr, size);

  printf("\nMax = %d\n", max);
  printf("Min = %d\n", min);
  printf("SecondMax = %d\n", secondMax);
  printf("SecondMin = %d\n", secondMin);

  printf("\n");
  reverseArray(arr, size);
  printArray(arr, size);

  printf("\nSorted Array:\n");
  bubbleSort(arr, size);
  printArray(arr, size);

  int rows, cols;
  printf("Enter the rows = ");
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "Invalid input. Exiting!\n");
    return 1;
  }

  printf("Enter the number of cols = ");
  if (scanf("%d", &cols) != 1) {
    fprintf(stderr, "Invalid input. Exiting!\n");
    return 1;
  }

  int **arr2d; // Declare a double pointer for the 2d array

  // Dynamically create an array
  arr2d = create2DArr(rows, cols);
  if (!arr2d) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  // Take the 2D array
  take2DArray(arr2d, rows, cols);

  // Print the 2D array
  print2DArray(arr2d, rows, cols);
  // Print in matrix form
  print2DMatrix(arr2d, rows, cols);

  return 0;
}
