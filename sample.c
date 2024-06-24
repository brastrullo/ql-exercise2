#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

void readAndPrintFile(const char* filename) {
    FILE *f;
    char c;
    f=fopen("test.txt","rt");

    char buff[BUFSIZE];

    while (fgets(buff, BUFSIZE, f) != NULL) {
        printf("%s", buff);
    }

    fclose(f);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readAndPrintFile(argv[1]);
    
    return 0;
}