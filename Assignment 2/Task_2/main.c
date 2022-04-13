#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *print()
{
	printf("Process ID: %d and Thread ID: %lu\n", getpid(), pthread_self());
}

int main()
{
	pthread_t threads[7];

	for (int i = 0; i < 7; i++)
	{
		pthread_create(&threads[i], NULL, print, NULL);
	}
	for (int j = 0; j < 7; j++)
	{
		pthread_join(threads[j], NULL);
	}

	return 0;
}