#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        printf("Child Created, PID: %d\n", getpid());
    }
    if (fork() == 0)
    {
        printf("Child Created, PID: %d\n", getpid());
    }
    if (fork() == 0)
    {
        printf("Child Created, PID: %d\n", getpid());
    }
    if (fork() == 0)
    {
        printf("Child Created, PID: %d\n", getpid());
    }

    return 0;
}