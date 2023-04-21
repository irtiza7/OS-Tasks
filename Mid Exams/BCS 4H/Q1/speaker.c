#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pipe_fd = open("story_pipe", O_RDWR);
  char *quote = "a computer would deserve to be called intelligent if it could "
                "deceive a human into believing that it was human";
  int write_status = write(pipe_fd, quote, strlen(quote));
  return 0;
}