#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define INPUT_SIZE 50

int main()
{
    char input[INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);
    printf("String: \n%s", input);

    char *args[] = {"./reverse", input, 0};

    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
    }
    else if (pid == -1)
    {
        perror("Fork Failed");
    }

    wait(NULL);
    return 0;
}