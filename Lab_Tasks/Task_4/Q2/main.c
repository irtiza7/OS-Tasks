#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        char *dir_name = "demo_folder";
        char *program = "mkdir";
        // execlp(program_name, program_name, args, NULL)
        execlp(program, program, dir_name, NULL);
    }
    else
    {
        wait(NULL);
        if (fork() == 0)
        {
            char *program = "touch";
            char *args[] = {"touch", "./demo_folder/file1.txt", "./demo_folder/file2.txt", NULL};
            // eexecvp(program_name, arguments_vector ENDING WILL NULL)
            execvp(program, args);
        }
        else
        {
            wait(NULL);
            if (fork() == 0)
            {
                char *program = "ls";
                char *args[] = {"ls", "./demo_folder", NULL};
                // eexecvp(program_name, arguments_vector ENDING WILL NULL)
                execvp(program, args);
            }
            else
            {
                wait(NULL);
                sleep(2);
                if (fork() == 0)
                {
                    char *program = "rm";
                    char *args[] = {"rm", "-rf", "./demo_folder", NULL};
                    // execlp(program_name, program_name, args, NULL)
                    execvp(program, args);
                }
                else
                {
                    wait(NULL);
                }
            }
        }
    }
    return 0;
}