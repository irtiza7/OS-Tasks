#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *string = argv[1];
  printf("MAIN [PID: %d]\nString: %s\n", getpid(), string);

  int fd[2];
  int pipe_status = pipe(fd);
  int write_status = write(fd[1], string, strlen(string));

  if (fork() == 0) {
    dup2(fd[0], 10);
    int exec_status = execl("./frequencies.exe", "frequencies.exe", NULL);
    printf("Exec Status: %d\n", exec_status);
    return 0;
  }

  // Wait until the child returns, otherwise the pipe will be deleted
  wait(NULL);
  return 0;
}