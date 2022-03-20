#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char cmnd_1[] = {"cat"};
    char cmnd_2[] = {"wc"};
    char *args[] = {cmnd_1, argv[1], 0};

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child 1: running CAT command\n");
        execvp(args[0], args);
    }
    else if (pid == -1)
    {
        perror("Fork Failed\n");
    }
    else
    {
        wait(NULL);
        args[0] = cmnd_2;
        pid = fork();

        if (pid == 0)
        {
            printf("\nChild 2: running WC command\n");
            execvp(args[0], args);
        }

        wait(NULL);
        return 0;
    }
}