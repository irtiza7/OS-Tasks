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
  int status = mkfifo("story_pipe", 0666);
  printf("Status: %d\n", status);
  return 0;
}