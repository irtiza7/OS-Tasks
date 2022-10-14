#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 15

int main(int argc, char *argv[])
{
    char *pipe_name = argv[1];
    int fd = open(pipe_name, O_RDWR);

    pid_t myid = getpid();
    printf("Handler [ID = %d]\n", myid);

    char string[] = "a DEMO stRiNG\0";

    write(fd, string, SIZE);
    sleep(3);
    read(fd, string, SIZE);
    
    printf("Case_Converter Sent: %s\n", string);
    close(fd);
    return 0;
}



