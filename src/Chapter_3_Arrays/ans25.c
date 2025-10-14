// Insert an element at the specified position in a floating point array.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int main() {
  int size;
  printf("Enter the size of the array (must be less than 50): ");
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Invalid Input! Exiting.\n");
    return 1;
  }

  if (size >= MAX_SIZE) {
    printf("Size cannot be equal to or greater than 50\n");
    return 1;
  }

  float *A = malloc(sizeof(float) * size);

  for (int i = 0; i < size; i++) {
    printf("Enter element at index [%d] = ", i);
    if (scanf("%f", (A + i)) != 1) {
      fprintf(stderr, "Invalid input! Exiting.\n");
      return 1;
    }
  }

  printf("\nThis is the array you entered:\n");
  for (int i = 0; i < size; i++) {
    printf("Element at index [%d] = %f\n", i, A[i]);
  }
  printf("\n");

  printf("Enter the index at which you want to insert another floating point "
         "number:\n");
  int index = 0;
  float num = 0.0;

  if (scanf("%d", &index) != 1) {
    fprintf(stderr, "Invalid Input. Exiting!\n");
    return 1;
  }

  printf("\nEnter the number that you want to insert at %d = ", index);
  if (scanf("%f", &num) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  int i;
  for (i = size; i > index; i--) {
    A[i] = A[i - 1];
  }
  A[i] = num;

  printf("Array after insertion is:\n");
  for (i = 0; i < size + 1; i++) {
    printf("Element at %d = %.3f\n", i, A[i]);
  }

  free(A);

  return 0;
}
