#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");

    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }

    char buff[BUFSIZE];

    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }

    return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  if (read_file(argv[1]) == -1) {
    printf("Failed to read file '%s'\n", argv[1]);
    return -1;
  }

  return 0;
}
