#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define INPUT_SIZE 50

int main() {
  char input[INPUT_SIZE];
  char *ptr = fgets(input, INPUT_SIZE, stdin);
  printf("[MAIN] - String: %s", input);

  char *args[] = {"./reverse", input, NULL};
  int exec_status = execvp(args[0], args);
  printf("Exec Status: %d\n", exec_status);
  return 0;
}