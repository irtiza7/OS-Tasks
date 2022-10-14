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
    int elements;
    int size;
    int sum = 0;
    
    read(fd, &elements, sizeof(int));
    printf("Calculator - Elements: %d\n", elements);
    read(fd, &size, sizeof(int));
    printf("Calculator - Size: %d\n", size);
    
    int recv_arr[elements];
    read(fd, recv_arr, size);

    printf("Calculator - ");
    for(int i = 0; i < elements; i++){
        printf("%d ", recv_arr[i]);
        sum += recv_arr[i];
    }
    
    printf("\n");
    sleep(2);
    write(fd, &sum, sizeof(int));
    close(fd);
    return 0;
}