/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/08 17:05:50 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->print);
	data->cnt += 1;
	pthread_mutex_unlock(&data->print);
	while (1)
	{
		pthread_mutex_lock(&data->print);
		if (data->cnt > data->number_of_philosophers)
		{
			pthread_mutex_unlock(&data->print);
			break;
		}
		pthread_mutex_unlock(&data->print);
	}
	pthread_mutex_lock(&data->print);
	printf("philo id : %d cnt : %d\n", philo->id, philo->data->cnt);
	pthread_mutex_unlock(&data->print);
	return (NULL);
}

void	make_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < (philos)->data->number_of_philosophers)
	{
		pthread_create(&(philos)[i].thread, NULL, philo, &(philos)[i]);
		usleep(100000);
		i++;
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
	// print_philos(&data);
	make_thread(philo);
	return (0);
}
