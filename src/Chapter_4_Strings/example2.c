// This program converts the lower case characters
// in a string into upper case.

#include <stdio.h>

int main() {
  char str[100], upper_str[100];
  int i = 0;
  printf("\n Enter the string.\n");
  if (fgets(str, sizeof(str), stdin) == NULL) {
    printf("Error in taking input.\n");
    return 1;
  }

  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      upper_str[i] = str[i] - 32;
    } else {
      upper_str[i] = str[i];
    }
    i++;
  }

  upper_str[i] = '\0';
  printf("\n The string converted into upper case is: ");
  puts(upper_str);
  return 0;
}
