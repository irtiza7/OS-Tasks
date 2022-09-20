#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    printf("My ID: %d\n", getpid());

    char *program = "my_info";
    char *args[] = {"my_info", "my_info", NULL};
    execv(program, args);
    return 0;
}