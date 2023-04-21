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
	printf("MAIN [PID: %d]\nSentence: %s\n", getpid(), sentence);
	int exec_status = execl("./reverse.exe", "reverse.exe", sentence, NULL);
	printf("Exec Status: %d\n", exec_status);
	return 0;
}