#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void change_case(char *string);

int main()
{
    char *send_buffer = "Winter is coming.";
    int SIZE = strlen(send_buffer);
    char recv_buffer[SIZE];

    int fd[2];
    pipe(fd);

    pid_t child_id = fork();
    if (child_id > 0)
    {
        printf("Parent Process [ID: %d]\n", getpid());
        write(fd[1], send_buffer, SIZE);
    }
    else
    {
        read(fd[0], recv_buffer, SIZE);
        printf("Child Process [ID: %d] \nOriginal String: %s\n", getpid(), recv_buffer);
        change_case(recv_buffer);
    }
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
    printf("Modified String: %s\n", string);
}