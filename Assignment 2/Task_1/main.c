#include <stdio.h>
#include <omp.h>

int main()
{
	char input;
	int threads;

	printf("Enter a character> ");
	scanf("%c", &input);
	printf("Enter number of threads for printing the character> ");
	scanf("%d", &threads);
	printf("Printing %c for %d times:\n", input, threads);

	omp_set_dynamic(0);
	omp_set_num_threads(threads);

#pragma omp parallel
	printf("%c\n", input);

	return 0;
}