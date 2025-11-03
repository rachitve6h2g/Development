// This program takes two strings: source string and destination string.
// It appends the source string to the destination string.

#include <stdio.h>
#include <string.h>

int main() {
  char src_str[100], dest_str[100];

  // Take the source string
  printf("\nEnter the source string: ");
  if (fgets(src_str, sizeof(src_str), stdin) == NULL) {
    printf("Error in taking input!\n");
    return 1;
  }

  // Take the destination string.
  printf("\nEnter the destination string: ");
  if (fgets(dest_str, sizeof(dest_str), stdin) == NULL) {
    printf("Error in taking input.\n");
    return 1;
  }

  // Remove the trailing space from both of them using the
  // "string complment span"(strcspn) function.
  src_str[strcspn(src_str, "\n")] = '\0';
  dest_str[strcspn(dest_str, "\n")] = '\0';

  // Count the length of the destination string.
  int i = 0;
  while (dest_str[i] != '\0') {
    i++;
  }

  // count the length of the src_str.
  int j = 0;
  while (src_str[j] != '\0') {
    dest_str[i] = src_str[j];
    i++;
    j++;
  }

  dest_str[i] = '\0';
  printf("\nAfter appending the destination string is: ");
  puts(dest_str);
  return 0;
}
