#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "my_header.h"

int main(int argc, char *argv[]) {
  int vovel_freq = 0;
  int constonants_freq = 0;
  char string[100];

  // Reading data from pipe's read end
  int len_read = read(10, string, 100);

  for (int i = 0; i < strlen(string); i++) {
    char ch = string[i];

    if (is_vovel(ch)) {
      vovel_freq++;
    } else {
      constonants_freq++;
    }
  }
  printf("FREQUENCIES [PID: %d]\n", getpid());
  printf("Frequencies of Vovels: %d\n", vovel_freq);
  printf("Frequencies of Consonants: %d\n", constonants_freq);
  return 0;
}

int is_vovel(char ch) {
  switch (ch) {
  case 'a':
    return 1;
  case 'e':
    return 1;
  case 'i':
    return 1;
  case 'o':
    return 1;
  case 'u':
    return 1;
  default:
    return 0;
  }
}