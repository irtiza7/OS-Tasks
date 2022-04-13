#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1()
{
	int c = 0;
	while (c++ < 100)
	{
		printf("Hello!!\n");
	}
}

void *thread2()
{
	int c = 0;
	while (c++ < 100)
	{
		printf("How are you?\n");
	}
}

int main()
{
	int status;
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}