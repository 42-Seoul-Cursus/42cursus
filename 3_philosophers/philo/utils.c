/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:06:53 by seunan            #+#    #+#             */
/*   Updated: 2023/10/23 16:28:04 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spend_time(t_philo *philo, unsigned int us)
{
	struct timeval	start;
	struct timeval	cur;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&cur, NULL);
		if (is_dead(philo->data))
			return (1);
		if (get_us(cur, start) >= us)
			return (0);
		usleep(100);
	}
	return (1);
}

unsigned long long	get_us(struct timeval cur, struct timeval start)
{
	return ((cur.tv_sec - start.tv_sec) * 1000000
		+ (cur.tv_usec - start.tv_usec));
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
