// Answer#1 to the programming exercises
#include "array_utils.h"
#include <stdio.h>

int main() {
  int rows = 20, cols = 5;
  printf("Enter the number of students = ");
  if (scanf("%d", &rows) != 1) {
    fprintf(stderr, "Invalid input! Exiting.\n");
    return 1;
  }

  printf("Enter the number of subjects = ");
  (void)scanf("%d", &cols);
  int **MARKS = create2DArr(rows, cols); // no. of students = 20, no. of
  // subjects = 5

  take2DArray(MARKS, rows, cols);  // Take an Array
  print2DArray(MARKS, rows, cols); // Print an Array

  // answer a; average of each subject
  for (int i = 0; i < cols; i++) {
    int sum = 0;
    float avg = 0.0;
    for (int j = 0; j < rows; j++) {
      sum += *(*(MARKS + j) + i);
    }

    avg = (float)sum / rows;
    printf("The average of subject number %d is %.2f\n", i, avg);
  }

  printf("\n");

  // answer b; average of each student
  for (int i = 0; i < rows; i++) {
    int sum = 0;
    float avg = 0.0;
    for (int j = 0; j < cols; j++) {
      sum += *(*(MARKS + i) + j);
    }

    avg = (float)sum / cols;
    printf("The average of student number %d is %.2f\n", i, avg);
  }
  return 0;
}
