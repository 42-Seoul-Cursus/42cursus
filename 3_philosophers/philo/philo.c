/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:32:46 by seunan            #+#    #+#             */
/*   Updated: 2023/10/24 12:37:32 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_mutex_lock(&(philo[i].lock));
		if (get_us(cur, philo[i].last_eat) / 1000
			>= (unsigned long long) philo->data->t2d)
		{
			pthread_mutex_unlock(&(philo[i].lock));
			pthread_mutex_lock(&(philo->data->lock));
			philo->data->dead = 1;
			pthread_mutex_unlock(&(philo->data->lock));
			print_dead(&(philo[i]), cur);
			break ;
		}
		pthread_mutex_unlock(&(philo[i].lock));
		pthread_mutex_lock(&(philo[i].lock));
		if (philo->data->must_eat > 0
			&& philo[i].eat_cnt >= philo->data->must_eat)
		{
			if (philo[i].is_full == 0)
			{
				philo[i].is_full = 1;
				++cnt;
			}
			if (cnt == philo->data->num)
			{
				pthread_mutex_unlock(&(philo[i].lock));
				pthread_mutex_lock(&(philo->data->lock));
				philo->data->dead = 1;
				pthread_mutex_unlock(&(philo->data->lock));
				print_success(philo);
				break ;
			}
		}
		pthread_mutex_unlock(&(philo[i].lock));
		++i;
	}
}

void	join_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num)
	{
		if (pthread_join(philo[i].thread, NULL) == 0)
			++i;
	}
}
