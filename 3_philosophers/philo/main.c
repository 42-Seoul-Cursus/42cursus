#include "philo.h"

pthread_mutex_t	g_mutex;

void	*philo(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&g_mutex);
	printf("Thread received argument: %d\n", data->number_of_philosophers);
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

void	make_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philos[i].thread, NULL, philo, data);
		usleep(100);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_data	data;

	init_data(&data, ac, av);
	check_data(&data, ac);
	// print_philos(&data);
	make_thread(&data);
	return (0);
}
