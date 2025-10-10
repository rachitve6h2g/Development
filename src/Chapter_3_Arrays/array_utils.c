#include "array_utils.h"
#include <stdio.h>

int takeArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter element %d: ", i);
    scanf("%d", arr + i);
  }
  printf("\n");
  return 0;
}

int printArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Element at index %d: %d\n", i, *(arr + i));
  }
  printf("\n");
  return 0;
}

int sumOfElements(int *arr, int size) {
  int i, sum = 0;
  for (i = 0; i < size; i++) {
    sum = sum + *(arr + i);
  }
  printf("\n");
  return sum;
}
