#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

void readAndPrintFile(const char* filename) {
    FILE* ptr = fopen(filename, "r");

    // Check for invalid sequences in the filename
    if (strstr(filename, "..") || strchr(filename, '/') || strchr(filename, '\\')) {
        printf("Invalid filename.\n");
        return;
    }

    // Check if file can be opened
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    char buff[BUFSIZE];

    // Read and print file contents
    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }

    fclose(ptr); // Close the file after reading
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readAndPrintFile(argv[1]);
    
    return 0;
}