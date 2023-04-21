#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int lengthOfString(char *string);

int main(int argc, char *argv[]) {
  printf("[FIND_LENGTH] - Length of String: %d\n", lengthOfString(argv[1]));
  char *args[] = {"./sort", argv[1], 0};
  execvp(args[0], args);
  return 0;
}

int lengthOfString(char *string) {
  int length = 0;
  int i = 0;
  while (string[i] != '\0') {
    length++;
    i++;
  }
  return length;
}