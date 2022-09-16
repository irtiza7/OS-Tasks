#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

void printArray(int array[]);
void sortAndPrintArray(int array[]);

int main(int argc, char *argv[])
{
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0)
    {
        sortAndPrintArray(numbers);
        printf("\nThis is Child Process with PID: %d \n", getpid());
    }
    return 0;
}

void printArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
}
void sortAndPrintArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printArray(array);
}