#include <stdio.h>
#include <math.h>
#include <omp.h>

int getArraySize(){
	int size;
	printf("Enter Array Size: ");
	scanf("%d", &size);
	return size;
}

int getKey(){
	int key;
	printf("Enter key: ");
	scanf("%d", &key);
	return key;
}

void printCount(int c){
	printf("Count: %d\n", c);
}

int main()
{
	int arrayLenght = getArraySize();
	int elements[arrayLenght];

	printf("Enter Elements to insert into array: \n");
	for(int i = 0; i < arrayLenght; i++){
		scanf("%d", &elements[i]);
	}

	int key = getKey();
	int count = 0;
	
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	
#pragma omp parallel for reduction(+:count)
    for (int i = 0; i < arrayLenght; i++)
    {
        if (key == elements[i])
        {
#pragma omp critical
            {
                count++;
            }
        }
    }
	printCount(count);
	return 0;
}