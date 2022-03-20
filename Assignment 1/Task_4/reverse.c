#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void reverseString(char *string)
{
    int length = strlen(string);
    char temporary;

    for (int i = 0; i < length / 2; i++)
    {
        temporary = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temporary;
    }
}

int main(int argc, char *argv[])
{
    char *args[] = {"./length", argv[1], 0};

    reverseString(argv[1]);
    printf("Reverse of String: %s\n", argv[1]);

    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(args[0], args);
    }
    else if (pid == -1)
    {
        perror("Fork Failed");
    }

    printf("Reverse program ended\n");
    wait(NULL);
    return 0;
}