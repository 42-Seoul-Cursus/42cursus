# philosopher

- [philosopher](#philosopher)
	- [`<unistd.h>`](#unistdh)
	- [`<stdio.h>`](#stdioh)
	- [`<stdlib.h>`](#stdlibh)
	- [`<string.h>`](#stringh)
	- [`<sys/time.h>`](#systimeh)
	- [`<pthread.h>`](#pthreadh)
	- [Trouble](#trouble)

## `<unistd.h>`

```c
write(int fd, const void *buf, size_t count)
usleep(useconds_t usec)
// 이 함수는 주어진 마이크로초(1/1,000,000 초) 동안 현재 스레드 또는 프로세스를 대기하게 합니다.
```

## `<stdio.h>`

```c
printf(const char *format, ...)
```

## `<stdlib.h>`

```c
malloc(size_t size)
free(void *ptr)
```

## `<string.h>`

```c
memset(void *s, int c, size_t n)
```

## `<sys/time.h>`

```c
gettimeofday(struct timeval *tv, struct timezone *tz)
// 이 함수는 현재 시간을 초와 마이크로초로 반환합니다.
// tv: 현재 시간 정보(1970-01-01 00:00 부터 함수가 호출된 시간까지의 ms 값)를 저장할 구조체입니다.
// tz: 시간대 정보를 저장할 구조체입니다. (일반적으로 사용되지 않으며, NULL 포인터로 전달하는 경우가 많습니다)
```

## `<pthread.h>`

```c
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
// 이 함수는 새로운 스레드를 생성합니다. 생성된 스레드는 start_routine 함수를 실행하며 arg를 매개변수로 전달합니다.
pthread_detach(pthread_t thread)
// 이 함수는 스레드를 분리합니다. 분리된 스레드는 종료 후 자동으로 정리됩니다. 일반적으로 pthread_create 함수에서 생성된 스레드를 분리할 때 사용됩니다.
pthread_join(pthread_t thread, void **retval)
// 이 함수는 스레드의 실행이 종료될 때까지 대기하며, 스레드가 종료하면 스레드의 반환 값을 retval에 저장합니다.
pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
// 이 함수는 뮤텍스(뮤티언트 엑스클루시브, 상호 배타적)를 초기화합니다. 뮤텍스는 다중 스레드 간의 공유 자원에 대한 동시 접근을 조절하는 데 사용됩니다.
pthread_mutex_destroy(pthread_mutex_t *mutex)
// 이 함수는 뮤텍스를 해제하고 정리합니다.
pthread_mutex_lock(pthread_mutex_t *mutex)
pthread_mutex_unlock(pthread_mutex_t *mutex)
// 이 두 함수는 뮤텍스를 사용하여 크리티컬 섹션(동시에 하나의 스레드만 접근 가능한 섹션)을 보호합니다. pthread_mutex_lock 함수는 뮤텍스를 잠그고, pthread_mutex_unlock 함수는 뮤텍스를 해제합니다.
```

## Trouble

```c
		// 기존에 1ms씩 당겨서 출력되는 문제가 있었음
		gettimeofday(&cur, NULL);
		time = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
		pthread_mutex_lock(&philo->data->print);
		printf("%d %d has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->print);


		// print lock 안에서 시간을 측정하고 출력하니까 해결됨
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&cur, NULL);
		time = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
		printf("%d %d has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
```
