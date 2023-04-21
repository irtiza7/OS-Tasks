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

int main(int argc, char *argv[]){
	char *sentence = argv[1];
	int length = find_length(sentence);
	
	printf("FIND LENGTH [PID: %d]\nString Length: %d\n", getpid(), length);
	
	int exec_status = execl("./vovel_frequency.exe", "vovel_frequency.exe", sentence, NULL);
	printf("Exec Status: %d\n", exec_status);
	return 0;
}

int find_length(char string[100]){
	int length = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}