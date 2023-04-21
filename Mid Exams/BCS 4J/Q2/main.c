#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 300

int main(int argc, char *argv[]) {
  int p1_fd[2];
  int p2_fd[2];
  int p1_status = pipe(p1_fd);
  int p2_status = pipe(p2_fd);

  char *string = argv[1];
  int write_status = write(p1_fd[1], string, strlen(string));

  if (fork() == 0) {
    char string[MAX_SIZE];
    char processed_string[MAX_SIZE];

    int read_status = read(p1_fd[0], string, MAX_SIZE);

    for (int i = 0, j = 0; i < strlen(string); i++) {
      char ch = string[i];
      if ((ch > 47) && (ch < 58)) {
        processed_string[j] = ch;
        j++;
      }
    }

    for (int i = 0; i < strlen(processed_string); i++) {
      for (int j = i; j < strlen(processed_string); j++) {
        if (processed_string[i] < processed_string[j]) {
          char ch = processed_string[i];
          processed_string[i] = processed_string[j];
          processed_string[j] = ch;
        }
      }
    }

    write_status = write(p2_fd[1], processed_string, strlen(processed_string));
    return 0;
  }
  wait(NULL);

  char received_string[MAX_SIZE];
  int read_status = read(p2_fd[0], received_string, MAX_SIZE);
  printf("MAIN - Processed String: %s\n", received_string);
  return 0;
}