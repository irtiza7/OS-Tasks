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
    char operator;
    float operand1;
    float operand2;
    float result = 0.0;

    read(fd, &operator, sizeof(char));
    read(fd, &operand1, sizeof(float));
    read(fd, &operand2, sizeof(float));

    switch(operator){
        case '+':
        result = operand1 + operand2;
        break;
        case '-':
        result = operand1 - operand2;
        break;
        case '*':
        result = operand1 * operand2;
        break;
        case '/':
        result = operand1 / operand2;
        break;
        default:
        printf("Invalid Operator\n");
        exit(1);
    }
    
    write(fd, &result, sizeof(float));
    return 0;
}
