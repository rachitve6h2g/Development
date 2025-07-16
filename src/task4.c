#include <stdio.h>
#include <string.h>

void runLengthEncode(const char *input) {
    int count;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        count = 1;

        // Count consecutive repeating characters
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Print character followed by count
        printf("%c%d", input[i], count);
    }

    printf("\n");
}

int main() {
    char input[1000];

    printf("Enter a string to encode: ");
    scanf("%999s", input);  // safer input read

    printf("Encoded string: ");
    runLengthEncode(input);

    return 0;
}
