#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct Information
{
	pid_t pid;
	pthread_t tid;
} INFORMATION;

void *threadHandler()
{
	INFORMATION *info = malloc(sizeof(INFORMATION));
	info->pid = getpid();
	info->tid = pthread_self();
	pthread_exit(info);
}

int main()
{
	pthread_t threads[7];
	INFORMATION *returnedValues[7];

	for (int i = 0; i < 7; i++)
	{
		pthread_create(&threads[i], NULL, threadHandler, NULL);
	}
	for (int j = 0; j < 7; j++)
	{
		pthread_join(threads[j], (INFORMATION *)&returnedValues[j]);
	}
	for (int k = 0; k < 7; k++)
	{
		printf("Process ID: %d and Thread ID: %lu\n", returnedValues[k]->pid, returnedValues[k]->tid);
	}

	return 0;
}