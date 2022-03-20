#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if(fork() == 0) {
        printf("A Child Created\n");
    }
    if(fork() == 0) {
        printf("A Child Created\n");
    }
    if(fork() == 0) {
        printf("A Child Created\n");
    }
    if(fork() == 0) {
        printf("A Child Created\n");
    }

    return 0;
}