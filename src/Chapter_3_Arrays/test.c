#include "array_utils.h"
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of the \narray you wanna create: ");
  scanf("%d", &size);

  int arr[size];

  takeArray(arr, size);
  printArray(arr, size);

  int sum = sumOfElements(arr, size);

  printf("Sum of the elements is: %d\n", sum);
  return 0;
}
