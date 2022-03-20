#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int lengthOfString(char *string)
{
    int length = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

int main(int argc, char *argv[])
{
    char *args[] = {"./sort", argv[1], 0};

    printf("Length of String: \n%d\n", lengthOfString(argv[1]));

    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(args[0], args);
    }
    else if (pid == -1)
    {
        perror("Fork Failed");
    }

    printf("Length Program Ended\n");
    wait(NULL);
    return 0;
}