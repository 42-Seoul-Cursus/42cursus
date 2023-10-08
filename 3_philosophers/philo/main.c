/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/08 22:28:41 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sit_table(t_philo *philo)
{
	while (1)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->forks[philo->left_fork]);

			pthread_mutex_lock(&philo->data->print);
			printf("timestamp_in_ms %d has taken a fork\n", philo->id);
			pthread_mutex_unlock(&philo->data->print);
		}
		else if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(&philo->data->forks[philo->right_fork]);

			pthread_mutex_lock(&philo->data->print);
			printf("timestamp_in_ms %d has taken a fork\n", philo->id);
			pthread_mutex_unlock(&philo->data->print);
		}
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->forks[philo->right_fork]);

			pthread_mutex_lock(&philo->data->print);
			printf("timestamp_in_ms %d is eating\n", philo->id);
			pthread_mutex_unlock(&philo->data->print);

			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		}
		else if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(&philo->data->forks[philo->left_fork]);

			pthread_mutex_lock(&philo->data->print);
			printf("timestamp_in_ms %d is eating\n", philo->id);
			pthread_mutex_unlock(&philo->data->print);

			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		}
	}

}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->print);
	data->cnt += 1;
	pthread_mutex_unlock(&data->print);
	while (1)
	{
		pthread_mutex_lock(&data->print);
		if (data->cnt == data->number_of_philosophers)
		{
			pthread_mutex_unlock(&data->print);
			break;
		}
		pthread_mutex_unlock(&data->print);
	}
	sit_table(philo);
	return (NULL);
}

void	make_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < (philos)->data->number_of_philosophers)
	{
		pthread_create(&(philos)[i].thread, NULL, philo_routine, &(philos)[i]);
		usleep(300);
		++i;
	}
	i = 0;
	while (pthread_join(philos[i].thread, NULL) != 0)
		++i;
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	data;

	init_data(&data, ac, av);
	check_data(&data, ac);
	philo = init_philos(&data);
	// print_philos(philo);
	make_thread(philo);
	return (0);
}
