#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd1[2];
    int fd2[2];

    pipe(fd1);
    pipe(fd2);

    int size = sizeof(int) * 5;
    int send_arr[] = {1, 5, 7, 2, 15};
    int recv_arr[size];

    pid_t child_id = fork();
    if (child_id > 0)
    {
        close(fd1[0]);
        close(fd2[1]);

        write(fd1[1], &send_arr, size);
        close(fd1[1]);

        wait(NULL);

        int sum = 0;
        read(fd2[0], &sum, sizeof(int));
        printf("Sum Received from Child: %d\n", sum);
        close(fd2[0]);
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], recv_arr, size);
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += recv_arr[i];
        }
        close(fd1[0]);
        write(fd2[1], &sum, sizeof(int));
        close(fd2[1]);

        exit(0);
    }
    return 0;
}