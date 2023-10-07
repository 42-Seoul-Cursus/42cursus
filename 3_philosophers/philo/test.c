#include "philo.h"

// 먹기 => 자기 => 생각하기

// av[1] = number_of_philosophers_and_forks
// av[2] = time_to_die_in_ms
// av[3] = time_to_eat_in_ms
// av[4] = time_to_sleep_in_ms
// av[5] = number_of_times_each_philosopher_must_eat (optional)

void	print_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		printf("philos[%d].id = %d\n", i, data->philos[i].id);
		printf("philos[%d].status = %d\n", i, data->philos[i].status);
		printf("philos[%d].last_eat_time = %d\n", i, data->philos[i].last_eat_time);
		printf("philos[%d].eat_count = %d\n", i, data->philos[i].eat_count);
		i++;
	}
}
