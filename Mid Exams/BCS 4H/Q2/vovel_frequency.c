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

int vovel_frequency = 0;

int main(int argc, char *argv[]){
	char *sentence = argv[1];
	update_frequency(sentence);
	
	printf("VOVEL FREQUENCY [PID: %d]\nVovels in the Sentence: %d\n", getpid(), vovel_frequency);

	int pipe_fd[2];
	int pipe_status = pipe(pipe_fd);

	int write_status = write(pipe_fd[1], sentence, strlen(sentence));
	dup2(pipe_fd[0], 10);
	
	if(fork() == 0){
		int exec_status = execl("./sort.exe", "sort.exe", NULL);
		printf("Exec Status: %d\n", exec_status);
	}

	// We have to wait for the child process to finish otherwise the pipe will be deleted
	wait(NULL);
	return 0;
}

void update_frequency(char string[100]){
	for(int i = 0; i < strlen(string); i++){
		if(is_vovel(string[i])){
			vovel_frequency++;
		}
	}
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