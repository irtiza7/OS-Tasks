#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH "/home/irtiza"

int main(int argc, char *argv[])
{
    char *args[] = {
        "/bin/sh",
        "-c",
        "ls /home/irtiza && ls > \"/home/irtiza/output1.txt\" /home/irtiza && grep \"output1.txt\" /home/irtiza/*.txt",
        0};

    // Exec launches a shell process which executes the concatenated commands for us in a sequence.
    int n = execve(args[0], &args[0], NULL);
    if (n == -1)
    {
        printf("Exec command failed.\n");
    }

    return 0;
}