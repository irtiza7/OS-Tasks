#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void update_frequencies(char *word);

int NUM_OF_STOPWORDS = 7;
char *STOP_WORDS[] = {"a", "the", "an", "of", "to", "in", "and"};
int frequencies[] = {0, 0, 0, 0, 0, 0, 0};

int main(int argc, char *argv[]) {
  char *sentence = argv[1];

  char word[20] = {};
  char ch;
  int word_len = 0;

  for (int i = 0; i < strlen(sentence); i++) {
    ch = sentence[i];

    // If the read character is a space then a single word is completed.
    // Hence we compare the word with stopwords.
    if (ch == ' ') {
      char temp_word[20] = {};
      for (int j = 0; j < word_len; j++) {
        temp_word[j] = word[j];
      }
      update_frequencies(temp_word);
      word_len = 0;
    } else {
      // If the read character is not a space then we keep on reading
      // characters.
      word[word_len] = ch;
      word_len++;
    }

    // The following statements handle the last word in the sentence.
    if ((i + 1) == strlen(sentence)) {
      char temp_word[20] = {};
      for (int j = 0; j < word_len; j++) {
        temp_word[j] = word[j];
      }
      update_frequencies(temp_word);
    }
  }

  int pipe_fd = open("fifo_pipe", O_RDWR);
  dup2(pipe_fd, 1);
  int write_status = write(1, frequencies, sizeof(frequencies));
  return 0;
}

void update_frequencies(char *word) {
  for (int i = 0; i < NUM_OF_STOPWORDS; i++) {
    if (!strcmp(word, STOP_WORDS[i])) {
      frequencies[i] += 1;
    }
  }
}