#include "philo.h"

// 먹기 => 자기 => 생각하기

// av[1] = number_of_philosophers_and_forks
// av[2] = time_to_die_in_ms
// av[3] = time_to_eat_in_ms
// av[4] = time_to_sleep_in_ms
// av[5] = number_of_times_each_philosopher_must_eat (optional)

void	print_philos(t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < philos[0].data->num)
	{
		printf("philos[%d].id = %d\n", i, philos[i].id);
		printf("philos[%d].status = %d\n", i, philos[i].status);
		printf("philos[%d].right_fork = %d\n", i, philos[i].right_fork);
		printf("philos[%d].left_fork = %d\n", i, philos[i].left_fork);
		printf("philos[%d].data = %p\n", i, philos[i].data);
		i++;
	}
}
