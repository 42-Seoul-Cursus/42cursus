/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/24 13:38:39 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	data;

	init_data(&data, ac, av);
	check_data(&data, ac);
	init_mutex(&data);
	philo = init_philo(&data);
	make_thread(philo);
	free_data(&philo);
	return (0);
}

void	free_data(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->data->num)
	{
		pthread_mutex_destroy(&((*philo)->data->forks[i]));
		pthread_mutex_destroy(&((*philo)->lock));
		++i;
	}
	pthread_mutex_destroy(&((*philo)->data->lock));
	pthread_mutex_destroy(&((*philo)->data->print));
	free((*philo)->data->forks);
	free(*philo);
}
