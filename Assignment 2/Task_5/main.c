#include <stdio.h>
#include <omp.h>

int main() {
    int arraySize;
    printf("Enter array size: ");
    scanf("%d", &arraySize);

    int numbers[arraySize];
    for(int i = 0; i < arraySize; i++) {
        printf("Enter value # %d: ", (i + 1));
        scanf("%d", &numbers[i]);
    }

    int key, keyCount = 0;
    printf("Enter the key you want to count: ");
    scanf("%d", &key);

#pragma omp parallel for schedule(static) reduction(+:keyCount)
    for(int i = 0; i < arraySize; i++)
        if(key == numbers[i])
            keyCount++;

    printf("Total count of %d in given array of numbers is: %d\n", key, keyCount);
    return 0;
}