#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_io.h"

char* s_scanf(int bufsize) {
  char* buffer = (char*)malloc(bufsize * sizeof(char));
  if (buffer == NULL) {
    perror("Error: s_scanf failed to allocate memory to input.");
    exit(EXIT_FAILURE);
  }

  if (fgets(buffer, bufsize, stdin) != NULL) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  } else {
    free(buffer);
    return NULL;
  }

  return buffer;
}

void s_printf(char* pCharArr) {
  if (pCharArr != NULL) {
    printf("You entered: %s\n", pCharArr);
    free(pCharArr);
  } else {
    printf("Error reading input.\n");
  }
}
