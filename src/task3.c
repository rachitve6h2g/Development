// Please read [[./notes.org]] first
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "int", "char", "float", "double", "if", "else", "while", "for", "return", "void",
    "break", "continue", "switch", "case", "default", "do", "struct", "typedef", "const"
};
const int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

// Check if a string is a C keyword
int is_keyword(const char *word) {
    for (int i = 0; i < keywordCount; ++i)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
   return 0;
}

// Check if a character is a valid operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '=' || ch == '<' || ch == '>' || ch == '%';
}

// Lexical analyzer function
void lexical_analyzer(FILE *fp) {
    char ch, buffer[100];
    int i = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                if (is_keyword(buffer))
                    printf("[Keyword]    %s\n", buffer);
                else
                    printf("[Identifier] %s\n", buffer);
                i = 0;
            }

            if (is_operator(ch)) {
                printf("[Operator]   %c\n", ch);
            }
        }
    }

    // Final buffer flush in case file ends with identifier
    if (i > 0) {
        buffer[i] = '\0';
        if (is_keyword(buffer))
            printf("[Keyword]    %s\n", buffer);
        else
            printf("[Identifier] %s\n", buffer);
    }
}

int main() {
    const char *filename = "sample_code.c";
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    printf("Lexical analysis of '%s':\n\n", filename);
    lexical_analyzer(fp);

    fclose(fp);
    return 0;
}
