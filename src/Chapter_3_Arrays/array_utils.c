#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return 0;
}

int takeArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter element %d: ", i);
    if (scanf("%d", arr + i) != 1) {
      fprintf(stderr, "Invalid input! Exiting.\n");
      return 1;
    }
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

int **create2DArr(int rows, int cols) {
  int **arr = malloc(rows * sizeof(int *));
  if (!arr) {
    return NULL;
  }
  for (int i = 0; i < rows; i++) {
    *(arr + i) = malloc(cols * sizeof(int));
    if (!arr[i]) {
      return NULL;
    }
  }
  return arr;
}

int take2DArray(int **arr, int rows, int columns) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      printf("Enter element at [%d][%d]: ", i, j);
      if (scanf("%d", (*(arr + i) + j)) != 1) {
        fprintf(stderr, "Invalid input! Exiting.\n");
        return 1;
      }
    }
  }

  printf("\n");
  return 0;
}

int print2DArray(int **arr, int rows, int columns) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      printf("Element at [%d][%d] = %d\n", i, j, *(*(arr + i) + j));
    }
  }

  printf("\n");
  return 0;
}

int print2DMatrix(int **arr, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d  ", *(*(arr + i) + j));
    }
    printf("\n");
  }
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

int maxElement(int *arr, int size) {
  int i, max;
  max = *(arr + 0); // Make the first element the max
  for (i = 1; i < size; i++) {
    if (*(arr + i) > max)
      max = *(arr + i);
  }
  printf("\n");
  return max;
}

int minElement(int *arr, int size) {
  int i, min;
  min = *(arr + i);

  for (i = 1; i < size; i++) {
    if (*(arr + i) < min)
      min = *(arr + i);
  }

  printf("\n");
  return min;
}

int secondMaxElement(int *arr, int size) {
  int i, pos, max, secondMax;
  max = *(arr + 0);
  for (i = 1; i < size; i++) {
    if (*(arr + i) > max) {
      secondMax = max;
      max = *(arr + i);
    } else if (*(arr + i) > secondMax && *(arr + i) < max)
      secondMax = *(arr + i);
  }

  printf("\n");
  return secondMax;
}

int secondMinElement(int *arr, int size) {
  int i, pos, min, secondMin;
  min = *(arr + 0);
  for (i = 1; i < size; i++) {
    if (*(arr + i) < min) {
      secondMin = min;
      min = *(arr + i);
    } else if (*(arr + i) < secondMin && *(arr + i) > min)
      secondMin = *(arr + i);
  }

  printf("\n");
  return secondMin;
}

int reverseArray(int *arr, int size) {
  int i, j;
  j = size - 1;
  for (i = 0; i < j; i++, j--)
    swap((arr + i), (arr + j));
  return 0;
}

int bubbleSort(int *arr, int size) {
  int i, j, swapped;
  for (i = 0; i < size - 1; i++) {
    swapped = 0;

    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
    }

    if (swapped == 0)
      break;
  }

  return 0;
}

int *mergeArr(int *arr, int *arr2, int size, int size2) {
  int *arr3, i;
  int size3 = size + size2;
  arr3 = malloc(sizeof(int) * size3);
  for (i = 0; i < size; i++) {
    arr3[i] = arr[i];
  }
  return arr3;
}
