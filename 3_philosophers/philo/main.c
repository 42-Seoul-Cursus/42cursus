/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/14 19:25:04 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&(philo->time), NULL);
	printf("%ld %d is sleeping\n", (philo->time.tv_sec - philo->data->start_time.tv_sec)  * 1000000 + (philo->time.tv_usec - philo->data->start_time.tv_usec), philo->id);
	pthread_mutex_unlock(&philo->data->print);
	usleep(philo->data->time_to_sleep_in_ms);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&(philo->time), NULL);
		printf("%ld %d has taken a fork\n", (philo->time.tv_sec - philo->data->start_time.tv_sec)  * 1000000 + (philo->time.tv_usec - philo->data->start_time.tv_usec), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&(philo->time), NULL);
		printf("%ld %d has taken a fork\n", (philo->time.tv_sec - philo->data->start_time.tv_sec)  * 1000000 + (philo->time.tv_usec - philo->data->start_time.tv_usec), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&(philo->time), NULL);
		printf("%ld %d is eating\n", (philo->time.tv_sec - philo->data->start_time.tv_sec)  * 1000000 + (philo->time.tv_usec - philo->data->start_time.tv_usec), philo->id);
		usleep(philo->data->time_to_eat_in_ms);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&(philo->time), NULL);
		printf("%ld %d is eating\n", (philo->time.tv_sec - philo->data->start_time.tv_sec)  * 1000000 + (philo->time.tv_usec - philo->data->start_time.tv_usec), philo->id);
		usleep(philo->data->time_to_eat_in_ms);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
}

void	sit_table(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		sleeping(philo);
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
			gettimeofday(&data->start_time, NULL);
			pthread_mutex_unlock(&data->print);
			break ;
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
		pthread_create(&(philos[i].thread), NULL, philo_routine, &(philos[i]));
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
	print_philos(philo);
	make_thread(philo);
	return (0);
}
