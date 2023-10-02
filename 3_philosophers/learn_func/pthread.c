#include <pthread.h>
#include <stdio.h>

void *myThreadFunction(void *arg)
{
	int *num = (int *)arg;
	printf("Thread received argument: %d\n", *num);
	return NULL;
}

int main(void)
{
	pthread_t thread;
	int argument = 42;

	if (pthread_create(&thread, NULL, myThreadFunction, &argument) != 0)
	{
		perror("Thread creation failed");
		return 1;
	}

	// Wait for the thread to finish
	if (pthread_join(thread, NULL) != 0)
	{
		perror("Thread join failed");
		return 1;
	}

	printf("Main thread exiting\n");
	return 0;
}
