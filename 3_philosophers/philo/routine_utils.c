/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:23:06 by seunan            #+#    #+#             */
/*   Updated: 2023/10/23 16:57:24 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		return (1);
	}
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	return (0);
}
