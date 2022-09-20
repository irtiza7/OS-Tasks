#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        char *program = "fibonacci";
        char *path = "./fibonacci";
        char *args[] = {"fibonacci", "15", NULL};
        execv(path, args);
    }
    return 0;
}