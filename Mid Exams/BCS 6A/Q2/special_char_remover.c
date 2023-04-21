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

  char processed_data[200];
  for (int i = 0, j = 0; i < strlen(data); i++) {
    char ch = data[i];
    if ((ch > 47) && (ch < 58)) {
      processed_data[j] = ch;
      j++;
    }
  }

  int write_status = write(pipe_fd, processed_data, strlen(processed_data));
  int exec_status = execl("./arranger", "./arranger", NULL);
  return 0;
}