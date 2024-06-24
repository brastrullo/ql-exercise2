#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    char *fileName = argv[2];
    // Check for invalid sequences in the user input
    if (strstr(fileName , "..") || strchr(fileName , '/') || strchr(fileName , '\\')) {
        printf("Invalid filename.\n");
        return 1;
    }

    char fileBuffer[BUFSIZE];
    snprintf(fileBuffer, sizeof(fileBuffer), "/home/user/files/%s", fileName);
    // GOOD: We know that the filename is safe and stays within the public folder
    FILE *file = fopen(fileBuffer, "wb+");
  
    if (file == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }

    char buff[BUFSIZE];

    while (fgets(buff, BUFSIZE, file) != NULL) {
        printf("%s", buff);
    }

    return 0;
}
