#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

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
    dup2(output_fd, 1);

    pid_t cat_child = fork();
    if (cat_child == 0)
    {
        execlp("cat", "cat", input_file_name, NULL);
    }
    else
    {
        wait(NULL);
    }
    return 0;
}