#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main()
{
    int i, j, k, x, y, z;
    long win = 0;
    int key = 111;
    double time1, time2, totalTime;

		time1 = omp_get_wtime();
	
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
		printf("[Sequential Code] Wins: %ld\n", win);
    time2 = omp_get_wtime();
		totalTime = time2 - time1;
    printf("Burst Time for Sequential Code: %lf\n\n", totalTime);

		win = 0;
    time1 = omp_get_wtime();
    omp_set_dynamic(0);
		omp_set_num_threads(2);
			
#pragma omp parallel for schedule(dynamic, 200) reduction(+:win)
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
    printf("[Parallel Code] Wins: %ld\n", win);
    time2 = omp_get_wtime();
		totalTime = time2 - time1;
    printf("Burst Time for Parallel Code (2 Threads): %lf\n\n", totalTime);

	win = 0;
    time1 = omp_get_wtime();
    omp_set_dynamic(0);
		omp_set_num_threads(3);
			
#pragma omp parallel for schedule(dynamic, 200) reduction(+:win)
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
    printf("[Parallel Code] Wins: %ld\n", win);
    time2 = omp_get_wtime();
		totalTime = time2 - time1;
    printf("Burst Time for Parallel Code (3 Threads): %lf\n\n", totalTime);

	win = 0;
    time1 = omp_get_wtime();
    omp_set_dynamic(0);
		omp_set_num_threads(4);
			
#pragma omp parallel for schedule(dynamic, 200) reduction(+:win)
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
    printf("[Parallel Code] Wins: %ld\n", win);
    time2 = omp_get_wtime();
		totalTime = time2 - time1;
    printf("Burst Time for Parallel Code (4 Threads): %lf\n", totalTime);
}