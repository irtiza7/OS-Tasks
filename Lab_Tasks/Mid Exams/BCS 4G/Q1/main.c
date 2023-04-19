#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int NUM_OF_STOPWORDS = 7;
char *STOP_WORDS[] = {"a", "the", "an", "of", "to", "in", "and"};

int main(void) {
  int file_fd = open("input.txt", O_RDWR);
  int stdin_fd = dup(0);
  dup2(file_fd, 0);

  char sentence[200];
  int len_read = read(0, sentence, 200);
  printf("Sentence: \n%s\n", sentence);

  dup2(stdin_fd, 0);

  if (fork() == 0) {
    char *args[] = {"worker_1.exe", sentence, NULL};
    int exec_status = execv("./worker_1.exe", args);
    printf("Exec Status: %d\n", exec_status);
    return 0;
  }

  int pipe_fd = open("fifo_pipe", O_RDWR);

  // Reading the output of worker 1
  int frequencies[NUM_OF_STOPWORDS];
  len_read = read(pipe_fd, frequencies, NUM_OF_STOPWORDS * sizeof(int));

  printf("Frequences: \n");
  for (int i = 0; i < NUM_OF_STOPWORDS; i++) {
    printf("%s > %d\n", STOP_WORDS[i], frequencies[i]);
  }

  if (fork() == 0) {
    char *args[] = {"worker_2.exe", sentence, NULL};
    int exec_status = execv("./worker_2.exe", args);
    printf("Exec Status: %d\n", exec_status);
    return 0;
  }

  // Reading the output of worker 2
  int number_of_words = 0;
  float average_word_length = 0.0;
  len_read = read(pipe_fd, &number_of_words, sizeof(int));
  len_read = read(pipe_fd, &average_word_length, sizeof(float));

  printf("\nWords in the Sentence: %d\n", number_of_words);
  printf("Average Word Length: %f\n", average_word_length);
  return 0;
}