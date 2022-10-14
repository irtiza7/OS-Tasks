#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *pipe_name = argv[1];
    int fd = open(pipe_name, O_RDWR);
    int elements = 5;
    int sum;
    int send_arr[] = {4, 5, 1, 5, 10};
    int size = elements * sizeof(int);

    printf("Handler - Elements: %d\n", elements);
    printf("Handler - Size: %d\n", size);

    write(fd, &elements, sizeof(int));
    sleep(2);
    write(fd, &size, sizeof(int));
    sleep(2);
    write(fd, send_arr, size);
    sleep(3);
    read(fd, &sum, sizeof(int));
    printf("Handler - Sum Received = %d\n", sum);
    close(fd);
    return 0;
}



