#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int order)
{
    if (order)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (array[j] < array[i])
                {
                    int tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (array[j] > array[i])
                {
                    int tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }

    printf("Sorted Elements: ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}

void findHighest(int array[], int nth)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (array[j] > array[i])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    printf("The %d highest value in the array is: %d\n", nth, array[nth - 1]);
}

void print(int array[])
{
    printf("Array Elements: ");

    for (int i = 0; i < 10; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}