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
  int file_fd = open(argv[1], O_RDWR);
  char data[200];
  int read_status = read(file_fd, data, 200);

  int pipe_fd = open("fifo", O_RDWR);
  int write_status = write(pipe_fd, data, strlen(data));

  int exec_status =
      execl("./special_char_remover", "./special_char_remover", NULL);
  return 0;
}