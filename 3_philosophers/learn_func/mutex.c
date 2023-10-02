#include <pthread.h>
#include <stdio.h>

pthread_mutex_t myMutex;

int main(void)
{
	// Initialize the mutex
	if (pthread_mutex_init(&myMutex, NULL) != 0) {
		perror("Mutex initialization failed");
		return 1;
	}

	// Use the mutex to protect a critical section
	pthread_mutex_lock(&myMutex);
	// ... Critical section code ...
	pthread_mutex_unlock(&myMutex);

	// Destroy the mutex when done
	pthread_mutex_destroy(&myMutex);

	return 0;
}
