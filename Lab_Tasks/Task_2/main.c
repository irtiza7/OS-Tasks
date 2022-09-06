#include <stdio.h>
#include "header.h"

int main(int argc, char *argv[])
{
    int order = atoi(argv[argc - 2]);
    int nth = atoi(argv[argc - 1]);
    int length = argc - 3;
    int array[10];

    for (int i = 0, j = 1; j <= 10; i++, j++)
    {
        array[i] = atoi(argv[j]);
    }

    print(array);
    sort(array, order);
    findHighest(array, nth);

    return 0;
}