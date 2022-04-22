#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main()
{
	double start, end, burst;

	int key = 111;
	int i, j, k;
	double x, y, z;
	long win = 0;

	start = omp_get_wtime();
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			for (k = 0; k < SIZE; k++)
			{
				x = (i * i * 1000 / 35) % 1000;
				y = (j * j * 1000 / 36) % 1000;
				z = (k * k * 1000 / 37) % 1000;

				if (key == (x + y + z))
				{
					win = win + 1;
				}
			}
		}
	}
	end = omp_get_wtime();
	burst = end - start;
	printf("Time Used: %lf\n", burst);
	printf("Total Wins:  %ld\n", win);
}
