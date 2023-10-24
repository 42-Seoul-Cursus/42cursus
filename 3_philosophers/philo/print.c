/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:22:07 by seunan            #+#    #+#             */
/*   Updated: 2023/10/23 16:56:55 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timestamp(t_philo *philo, char *s)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&cur, NULL);
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(&(philo->data->print));
		return (1);
	}
	printf("%llu %d %s\n", get_us(cur, philo->data->start_time) / 1000,
		philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

int	print_timestamp_eat(t_philo *philo)
{
	struct timeval	cur;

	pthread_mutex_lock(&(philo->data->print));
	gettimeofday(&cur, NULL);
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(&(philo->data->print));
		return (1);
	}
	pthread_mutex_lock(&philo->lock);
	philo->last_eat = cur;
	pthread_mutex_unlock(&philo->lock);
	printf("%llu %d is eating\n", get_us(cur, philo->data->start_time) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

void	print_success(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("\033[32m");
	printf("All philos ate %d times\n", philo->data->must_eat);
	printf("\033[0m");
	pthread_mutex_unlock(&(philo->data->print));
}

void	print_dead(t_philo *philo, struct timeval cur)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("\033[33m");
	printf("%llu %d died\n", get_us(cur, philo->data->start_time) / 1000,
		philo->id);
	printf("\033[0m");
	pthread_mutex_unlock(&(philo->data->print));
}

void	exit_with_err(char *err_msg)
{
	printf("\033[31m");
	printf("Error: %s\n", err_msg);
	printf("\033[0m");
	exit(EXIT_FAILURE);
}
