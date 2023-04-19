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
  char *sentence = argv[1];

  int number_of_alplabets = 0;
  int number_of_words = 0;
  float average_word_length = 0.0;
  char ch;
  int word_len = 0;

  for (int i = 0; i < strlen(sentence); i++) {
    ch = sentence[i];

    // If the read character is a space then a single word is completed.
    if (ch == ' ') {
      number_of_words++;
      number_of_alplabets += word_len;
      word_len = 0;
    } else {
      word_len++;
    }

    // The following statements handle the last word in the sentence.
    if ((i + 1) == strlen(sentence)) {
      number_of_words++;
      number_of_alplabets += word_len;
    }
  }
  average_word_length = (float)number_of_alplabets / (float)number_of_words;
  int pipe_fd = open("fifo_pipe", O_RDWR);
  int new_fd = dup2(pipe_fd, 1);
  int write_status = write(1, &number_of_words, sizeof(int));
  write_status = write(1, &average_word_length, sizeof(float));
  return 0;
}