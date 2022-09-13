#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);
    for (int i = 0; i < count; i++)
    {
        if (fork() == 0)
        {
            printf("Child Created with pid = %d\n", getpid());
            continue;
        }
        break;
    }
    wait(NULL);
    return 0;
}