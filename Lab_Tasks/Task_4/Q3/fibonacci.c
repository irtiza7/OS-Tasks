#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n1 = 0;
    int n2 = 1;
    int n3;
    int n = atoi(argv[1]);
    printf("argv[1]: %s, n: %d", argv[1], n);

    printf("\n%d %d", n1, n2);
    for (int i = 2; i < n; ++i)
    {
        n3 = n1 + n2;
        printf(" %d", n3);
        n1 = n2;
        n2 = n3;
    }
    return 0;
}