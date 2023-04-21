#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sortString(char *string);

int main(int argc, char *argv[]) {
  sortString(argv[1]);
  printf("[SORT] - Sorted String: %s\n", argv[1]);
  return 0;
}

void sortString(char *string) {
  int length = strlen(string);
  char temporary;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < (length - 1); j++) {
      if (string[j] > string[j + 1]) {
        temporary = string[j];
        string[j] = string[j + 1];
        string[j + 1] = temporary;
      }
    }
  }
}