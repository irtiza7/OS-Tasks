#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sortString(char *string)
{
    int length = strlen(string);
    char temporary;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1); j++)
        {
            if (string[j] > string[j + 1])
            {
                temporary = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temporary;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    sortString(argv[1]);
    printf("Sorted String: %s\n", argv[1]);
    printf("Sort program ended\n");
    return 0;
}