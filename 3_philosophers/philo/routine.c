/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:58 by seunan            #+#    #+#             */
/*   Updated: 2023/10/24 12:43:26 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->data->start_time;
	if (philo->data->num == 1)
	{
		take_left_fork(philo);
		if (spend_time(philo, philo->data->t2d * 1000) == 1)
		{
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
			return (NULL);
		}
	}
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

int	eating(t_philo *philo)
{
	if (take_left_fork(philo) == 1)
		return (1);
	if (take_right_fork(philo) == 1)
		return (1);
	if (lets_eat(philo) == 1)
		return (1);
	return (0);
}

int	lets_eat(t_philo *philo)
{
	if (print_timestamp_eat(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_lock(&philo->lock);
	++(philo->eat_cnt);
	pthread_mutex_unlock(&philo->lock);
	if (spend_time(philo, philo->data->t2e * 1000) == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_timestamp(philo, "is sleeping") == 1)
		return (1);
	if (spend_time(philo, philo->data->t2s * 1000) == 1)
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (print_timestamp(philo, "is thinking") == 1)
		return (1);
	return (0);
}
