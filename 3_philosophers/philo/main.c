/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/26 18:47:24 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		++i;
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->lock));
	free(data->forks);
}

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->data->num)
	{
		pthread_mutex_destroy(&((*philo)->lock));
		++i;
	}
	free(*philo);
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	data;

	if (init_data(&data, ac, av) == 1)
		return (1);
	if (init_mutex(&data) == 1)
		return (1);
	if (init_philo(&philo, &data) == 1)
	{
		free_data(&data);
		return (1);
	}
	make_thread(philo);
	free_philo(&philo);
	free_data(&data);
	return (0);
}
