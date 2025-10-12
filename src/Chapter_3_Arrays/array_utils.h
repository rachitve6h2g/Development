#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

int takeArray(int *arr, int size);  // take and
int printArray(int *arr, int size); // print an integer array

int **create2DArr(int rows, int cols);
int take2DArray(int **arr, int rows, int cols);
int print2DArray(int **arr, int rows, int cols);
int print2DMatrix(int **arr, int rows, int cols);

int sumOfElements(int *arr, int size); // To get the sum of elements in an array

int maxElement(int *arr, int size);
int minElement(int *arr, int size);
int secondMaxElement(int *arr, int size);
int secondMinElement(int *arr, int size);

int reverseArray(int *arr, int size);

int *mergeArr(int *arr, int *arr2, int size, int size2);

int bubbleSort(int *arr, int size);

#endif
