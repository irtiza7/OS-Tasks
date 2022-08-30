#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float average, sum = 0;
    for (int i = 1; i < argc; i++)
    {
        // atof() converts ASCII value to float
        sum += atof(argv[i]);
    }
    average = sum / (argc - 1);
    printf("Average: %lf\n", average);
    return 0;
}