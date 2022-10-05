#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);

    if (fork() == 0)
    {
        char content[100];
        int size;

        read(fd[0], &size, sizeof(int));
        read(fd[0], content, size);
        content[size] = '\0';

        printf("[CHILD: %d] - Size of Content to Receive: %d\n", getpid(), size);
        printf("[CHILD: %d] - Content Received: %s\n", getpid(), content);

        FILE *fptr = fopen(argv[2], "w");
        fputs(content, fptr);

        fclose(fptr);
        close(fd[0]);
        close(fd[1]);
        exit(0);
    }
    else
    {
        char content[100];
        FILE *fptr = fopen(argv[1], "r");
        fgets(content, 100, fptr);

        int size = strlen(content);
        printf("[PARENT: %d] - Size of Content to Send: %d\n", getpid(), size);
        write(fd[1], &size, sizeof(int));

        printf("[PARENT: %d] - Content to send: %s\n", getpid(), content);
        write(fd[1], content, size);

        fclose(fptr);
        close(fd[0]);
        close(fd[1]);
    }
    return 0;
}