#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char string[200];

	// The fd of pipe's read end was duplicated to 10 in the vovel_frequency program
	int read_status = read(10, string, 200);
	sort_string(string);
	printf("SORT [PID: %d]\nSorted Sentence: %s\n", getpid(), string);
	return 0;
}

void sort_string(char string[200])
{
    int length = strlen(string);
    char temporary;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1); j++)
        {
            if (string[j] > string[j + 1])
            {
                temporary = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temporary;
            }
        }
    }
}