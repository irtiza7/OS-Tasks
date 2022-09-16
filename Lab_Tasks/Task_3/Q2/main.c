#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 10

void printArray(int array[]);
void ascSortAndPrintArray(int array[]);
void desSortAndPrintArray(int array[]);

int main(int argc, char *argv[])
{
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }

    if (fork() == 0)
    {
        printf("This is Child Process with PID: %d and Parent ID: %d\n", getpid(), getppid());
        ascSortAndPrintArray(numbers);
    }
    else
    {
        wait(NULL);
        if (fork() == 0)
        {
            printf("\nThis is Child Process with PID: %d and Parent ID: %d\n", getpid(), getppid());
            desSortAndPrintArray(numbers);
        }
        else
        {
            wait(NULL);
            printf("\nI am Parent with ID: %d\n", getpid());
        }
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

void ascSortAndPrintArray(int array[])
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

void desSortAndPrintArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printArray(array);
}