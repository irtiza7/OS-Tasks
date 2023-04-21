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

char reversed_string[100];

int main(int argc, char *argv[]){
	char *sentence = argv[1];
	reverse_string(sentence);
	
	printf("REVERSE [PID: %d]\nReversed Sentence: %s\n", getpid(), reversed_string);
	
	int exec_status = execl("./find_length.exe", "find_length.exe", sentence, NULL);
	printf("Exec Status: %d\n", exec_status);
	return 0;
}

void reverse_string(char string[100]){
	for(int i = strlen(string) - 1, j = 0; i >= 0; i--){
		reversed_string[j] = string[i];
		j++;
	}
}