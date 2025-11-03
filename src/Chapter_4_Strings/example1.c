// This a program to find the length of a string.
// It also counts in the whitespace and return (enter).
#include <ctype.h>
#include <stdio.h>

int main() {
  char str[100], i = 0, length = 0;
  printf("\n Enter the string: ");
  if (fgets(str, sizeof(str), stdin) == NULL) {
    printf("Error in reading input.\n");
    return 1;
  };
  while (str[i] != '\0') {
    if (!isspace((unsigned char)str[i])) { // This is function from ctype.h to
      // check for all kinds of whitespace.
      length++;
    }
    i++;
  }

  printf("\n The length of the string is : %d\n", length);
  return 0;
}
