// A string is passed as an argument to a function.

#include <stdio.h>

void display(char str[]) { printf("You entered: %s\n", str); }

int main() {
  char message[100];

  printf("Enter a string: ");
  if (fgets(message, sizeof(message), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    return 1;
  };

  display(message);

  return 0;
}
