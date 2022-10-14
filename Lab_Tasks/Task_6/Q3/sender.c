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
    /*
    Multiplication Sign * is a wild card or special character.
    So when you pass it through your shell terminal it is not handled correctly.
    Hence type "*" or \* to get the proper results.
    */

    char *pipe_name = argv[1];
    int fd = open(pipe_name, O_RDWR);
    char *operator = argv[2];
    float operand1 = atof(argv[3]);
    float operand2 = atof(argv[4]);
    float result = 0.0;


    write(fd, operator, sizeof(char));
    sleep(1);
    write(fd, &operand1, sizeof(float));
    sleep(1);
    write(fd, &operand2, sizeof(float));
    sleep(1);
    read(fd, &result, sizeof(float));
    
    printf("Sender - Result Received: %lf\n", result);
    return 0;
}



