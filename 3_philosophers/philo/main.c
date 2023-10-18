/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/18 16:44:35 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(unsigned int time)
{
	struct timeval	cur;
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(100);
		gettimeofday(&cur, NULL);
		if ((cur.tv_sec - start.tv_sec) * 1000000 + (cur.tv_usec - start.tv_usec) >= time)
			break ;
	}
}

void	print_eat(t_philo *philo)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	philo->last_eat = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->print);
	printf("%u %d is eating\n", philo->last_eat, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	spend_time(philo->data->t2e * 1000);
}

void	take_right_fork(t_philo *philo)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	gettimeofday(&cur, NULL);
	philo->last_eat = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->print);
	printf("%u %d has taken a fork\n", philo->last_eat, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}
void	take_left_fork(t_philo *philo)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	gettimeofday(&cur, NULL);
	philo->last_eat = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->print);
	printf("%u %d has taken a fork\n", philo->last_eat, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	sleeping(t_philo *philo)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	philo->last_eat = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->data->print);
	printf("%u %d is sleeping\n", philo->last_eat, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	spend_time(philo->data->t2s * 1000);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		take_right_fork(philo);
	else
		take_left_fork(philo);
	if (philo->id % 2 == 0)
	{
		take_left_fork(philo);
		print_eat(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	}
	else
	{
		take_right_fork(philo);
		print_eat(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(100);
	else
	{
		pthread_mutex_lock(&data->print);
		gettimeofday(&data->start_time, NULL);
		pthread_mutex_unlock(&data->print);
	}
	while (1)
	{
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	make_thread(t_philo *philos)
{

	unsigned int	i;

	i = 0;
	while (i < (philos)->data->num)
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
	// print_philos(philo);
	make_thread(philo);
	return (0);
}
