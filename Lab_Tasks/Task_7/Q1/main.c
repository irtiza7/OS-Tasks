#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_PERM (O_RDWR)

int main(int argc, char *argv[])
{
    char *input_file_name = argv[1];
    char *output_file_name = argv[2];

    int input_fd = open(input_file_name, FILE_PERM);
    int output_fd = open(output_file_name, FILE_PERM);
    if ((input_fd < 0) || (output_fd < 0))
    {
        printf("FILE ERROR - InputFile: %d and OutputFile: %d\n", input_fd, output_fd);
        return 0;
    }

    // Replacing stdin value with input file's file_descriptor
    dup2(input_fd, 0);

    char data[500];
    // 0 represents the stdin in FDT
    int status = read(0, data, 500);
    if (status < 0)
    {
        printf("READ ERROR - Status: %d\n", status);
        return 0;
    }

    // Replacing stdout value with output file's file_descriptor
    dup2(output_fd, 1);
    printf("%s", data);
    return 0;
}