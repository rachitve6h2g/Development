#include <stdio.h>
#include <stdlib.h>

void create_and_write_file(const char *filename) {
    FILE *fp = fopen(filename, "w");  // "w" mode creates or overwrites the file
    if (fp == NULL) {
        perror("Error creating file");
        exit(1);
    }
    fprintf(fp, "Hello, this is a new file.\n");
    fprintf(fp, "Writing initial content.\n");
    fclose(fp);
    printf("File created and written to successfully.\n");
}

void append_to_file(const char *filename) {
    FILE *fp = fopen(filename, "a");  // "a" mode appends to the file
    if (fp == NULL) {
        perror("Error opening file for appending");
        exit(1);
    }
    fprintf(fp, "Appending a new line.\n");
    fclose(fp);
    printf("Content appended to file successfully.\n");
}

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");  // "r" mode for reading
    if (fp == NULL) {
        perror("Error reading file");
        exit(1);
    }

    char ch;
    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("--- End of File ---\n");

    fclose(fp);
}

int main() {
    const char *filename = "sample.txt";

    create_and_write_file(filename);  // Create and write
    append_to_file(filename);         // Append new content
    read_file(filename);              // Read and display

    return 0;
}
