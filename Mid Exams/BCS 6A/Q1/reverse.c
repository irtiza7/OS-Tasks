#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void reverseString(char *string);

int main(int argc, char *argv[]) {
  reverseString(argv[1]);
  printf("[REVERSE] - Reversed String: %s\n", argv[1]);

  char *args[] = {"./find_length", argv[1], 0};
  int exec_status = execvp(args[0], args);
  printf("Exec Status: %d\n", exec_status);
  return 0;
}

void reverseString(char *string) {
  int length = strlen(string);
  char temporary;

  for (int i = 0; i < length / 2; i++) {
    temporary = string[i];
    string[i] = string[length - i - 1];
    string[length - i - 1] = temporary;
  }
}