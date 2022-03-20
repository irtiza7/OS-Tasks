#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if(fork() && (!fork())) {
        if(fork() || fork()) {
            fork();
        }
    }
    printf("hello\n");
    return 0;
}