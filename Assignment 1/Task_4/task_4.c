#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INPUT_SIZE 20

int main() {
    char input[INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);
    printf("%s", input);
    return 0;
}