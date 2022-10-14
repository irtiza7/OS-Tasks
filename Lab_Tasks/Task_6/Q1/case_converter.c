#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 15

void change_case(char *string);

int main(int argc, char *argv[])
{
    char *pipe_name = argv[1];
    int fd = open(pipe_name, O_RDWR);

    pid_t myid = getpid();
    printf("Case_Converter [ID = %d]\n", myid);

    char string[SIZE];
    read(fd, string, SIZE);
    printf("Handler Sent: %s\n", string);

    change_case(string);
    write(fd, string, SIZE);

    close(fd);
    return 0;
}

void change_case(char *string)
{
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
        else if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
    }
    printf("Case_Conveter - Modified String: %s\n", string);
}

