#include <stdarg.h>
#include <stdio.h>
int sum(int count, ...) {
  int sum = 0;
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    sum = sum + va_arg(args, int);
  }
  va_end(args);
  return sum;
}

int min(int count, ...) {
  va_list args;
  va_start(args, count);
  int min = va_arg(args, int);
  for (int i = 1; i < count; i++) {
    int t = va_arg(args, int);
    if (min > t) {
      min = t;
    }
  }
  va_end(args);
  return min;
}

int max(int count, ...) {
  va_list args;
  va_start(args, count);
  int max = va_arg(args, int);
  for (int i = 1; i < count; i++) {
    int t = va_arg(args, int);
    if (max < t) {
      max = t;
    }
  }
  va_end(args);
  return max;
}

int main() {
  printf("Sum of digits 4, 5 and 6 = %d\n", sum(3, 4, 5, 6));
  printf("Minimum of digits 4, 5 and 6 = %d\n", min(3, 4, 5, 6));
  printf("Max of the 4, 5, 6 = %d\n", max(3, 4, 5, 6));
}
