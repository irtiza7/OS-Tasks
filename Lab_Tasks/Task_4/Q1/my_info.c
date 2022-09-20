#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("My ID: %d\n", getpid());

    char *roll_num = "21L-7232";
    char *name = "Muhammad Irtaza";
    char *semester = "3";

    printf("Roll Num: %s, \nName: %s, \nSemester: %s\n", roll_num, name, semester);
    return 0;
}