#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *pipe_name = argv[1];
    char buffer[100];
    int fd = open(pipe_name, O_RDWR);
    if (fd < 0)
    {
        printf("Pipe Error - fd: %d\n", fd);
        return 0;
    }

    while (1)
    {
        printf("Message to Send: ");
        fgets(buffer, 100, stdin);
        write(fd, buffer, sizeof(buffer));
        sleep(0.5);

        if ((buffer[0] == 'q') || (buffer[0] == 'Q'))
        {
            break;
        }

        read(fd, buffer, sizeof(buffer));
        printf("Reply Received: %s\n", buffer);

        if ((buffer[0] == 'q') || (buffer[0] == 'Q'))
        {
            break;
        }
    }

    close(fd);
    return 0;
}