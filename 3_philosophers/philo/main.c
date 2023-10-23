/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/23 14:52:42 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	if (is_dead(philo->data))
		return (1);
	print_timestamp(philo, "is thinking", 0);
	return (0);
}

int	sleeping(t_philo *philo)
{
	print_timestamp(philo, "is sleeping", 0);
	if (spend_time(philo ,philo->data->t2s * 1000) == 1)
		return (1);
	return (0);
}

int	print_eat(t_philo *philo)
{
	print_timestamp(philo, "is eating", 1);
	philo->eat_cnt++;
	if (spend_time(philo ,philo->data->t2e * 1000) == 1)
		return (1);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	print_timestamp(philo, "has taken a fork", 0);
	return (0);
}
int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	print_timestamp(philo, "has taken a fork", 0);
	return (0);
}

int	eat_odd(t_philo *philo)
{
	if (take_right_fork(philo) == 1)
		return (1);
	print_eat(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	return (0);
}

int	eat_even(t_philo *philo)
{
	if (take_left_fork(philo) == 1)
		return (1);
	print_eat(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	return (0);
}

int	eating(t_philo *philo)
{
	if (take_right_fork(philo) == 1)
			return (1);
	if (eat_even(philo) == 1)
		return (1);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->data->start_time;
	if (philo->id % 2 == 0)
		spend_time(philo, philo->data->t2e * 1000);
	while (TRUE)
	{
		if (eating(philo) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
		if (thinking(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

void	join_philo(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->num)
	{
		if (pthread_join(philo[i].thread, NULL) == 0)
			++i;
	}
}

void	monitoring(t_philo *philo)
{
	int				i;
	int				cnt;
	struct timeval	cur;

	i = 0;
	cnt = 0;
	while (TRUE)
	{
		if (i == philo->data->num)
			i = 0;
		gettimeofday(&cur, NULL);
		if ((int)get_us(cur, philo[i].last_eat) / 1000 >= philo->data->t2d)
		{

			pthread_mutex_lock(&(philo->data->lock));
			philo->data->dead = 1;
			pthread_mutex_unlock(&(philo->data->lock));
			print_dead(&(philo[i]), cur);
			break;
		}
		if (philo->data->must_eat > 0 && philo[i].eat_cnt >= philo->data->must_eat)
		{
			if (philo[i].is_full == 0)
			{
				philo[i].is_full = 1;
				++cnt;
			}
			if (cnt == philo->data->num)
			{
				pthread_mutex_lock(&(philo->data->lock));
				philo->data->dead = 1;
				pthread_mutex_unlock(&(philo->data->lock));
				print_success(philo);
				break;
			}
		}
		++i;
	}
}

void	make_thread(t_philo *philo)
{
	int	i;

	i = 0;
	gettimeofday(&(philo->data->start_time), NULL);
	while (i < philo->data->num)
	{
		pthread_create(&(philo[i].thread), NULL, philo_routine, &(philo[i]));
		++i;
	}
	usleep(1000);
	monitoring(philo);
	join_philo(philo);
}

void	free_data(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->data->num)
	{
		pthread_mutex_destroy(&((*philo)->data->forks[i]));
		++i;
	}
	pthread_mutex_destroy(&((*philo)->data->lock));
	pthread_mutex_destroy(&((*philo)->data->print));
	free((*philo)->data->forks);
	free(*philo);
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	data;

	init_data(&data, ac, av);
	check_data(&data, ac);
	init_mutex(&data);
	philo = init_philo(&data);
	// print_philos(philo);
	make_thread(philo);
	free_data(&philo);
	return (0);
}
