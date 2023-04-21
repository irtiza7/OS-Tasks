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
  int pipe_fd = open("fifo", O_RDWR);
  char data[200];
  int read_status = read(pipe_fd, data, 200);

  for (int i = 0; i < strlen(data); i++) {
    for (int j = i; j < strlen(data); j++) {
      if (data[i] < data[j]) {
        char ch = data[i];
        data[i] = data[j];
        data[j] = ch;
      }
    }
  }

  int ordinary_pipe_fd[2];
  int pipe_status = pipe(ordinary_pipe_fd);

  int write_status = write(ordinary_pipe_fd[1], data, strlen(data));

  if (fork() == 0) {
    char sorted_data[200];
    read_status = read(ordinary_pipe_fd[0], sorted_data, 200);

    int output_file_fd = open("output.txt", O_RDWR);
    write_status = write(output_file_fd, sorted_data, strlen(sorted_data));
    close(output_file_fd);
  }
  // We have to wait for the child process to finish otherwise the pipe will be
  // deleted
  wait(NULL);
  return 0;
}