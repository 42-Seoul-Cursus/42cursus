/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:06:53 by seunan            #+#    #+#             */
/*   Updated: 2023/10/26 18:02:14 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spend_time(t_philo *philo, int ms)
{
	struct timeval	start;
	struct timeval	cur;

	gettimeofday(&start, NULL);
	while (is_dead(philo->data) != 1)
	{
		gettimeofday(&cur, NULL);
		if (get_ms(cur, start) >= (unsigned long long) ms)
			return (0);
		usleep(200);
	}
	return (1);
}

unsigned long long	get_ms(struct timeval cur, struct timeval start)
{
	return ((cur.tv_sec - start.tv_sec) * 1000000
		+ (cur.tv_usec - start.tv_usec)) / 1000;
}

int	is_dead(t_data *data)
{
	pthread_mutex_lock(&(data->lock));
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&(data->lock));
		return (1);
	}
	pthread_mutex_unlock(&(data->lock));
	return (0);
}

int	take_two_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		return (1);
	}
	if (philo->data->num == 1)
	{
		usleep(philo->data->t2d);
		return (1);
	}
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	return (0);
}
