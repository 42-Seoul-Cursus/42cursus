/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/20 23:02:41 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int ac, char *av[])
{
	int	i;

	if (!(ac == 5 || ac == 6))
		exit_with_err("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat]");
	data->num = ft_atoi(av[1]);
	data->t2d = ft_atoi(av[2]);
	data->t2e = ft_atoi(av[3]);
	data->t2s = ft_atoi(av[4]);
	data->must_eat = -2; // -1 atoi error, -2 no input
	data->dead = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&(data->print), NULL) != 0)
		exit_with_err("Mutex initialization failed");
	if (pthread_mutex_init(&(data->lock), NULL) != 0)
		exit_with_err("Mutex initialization failed");
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		exit_with_err("Malloc failed");
	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			exit_with_err("Mutex initialization failed");
		++i;
	}
}

t_philo	*init_philos(t_data *data)
{
	t_philo		*philos;
	int			i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->num);
	if (!philos)
		exit_with_err("Malloc failed");
	while (i < data->num)
	{
		init_philo(&philos[i], data, i);
		i++;
	}
	return (philos);
}

void	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id + 1;
	philo->right_fork = id;
	if (id == data->num - 1)
		philo->left_fork = 0;
	else
		philo->left_fork = id + 1;
	philo->eat_cnt = 0;
	philo->data = data;
}

void	check_data(t_data *data, int ac)
{
	if (data->num < 2)
		exit_with_err("Error: Wrong number of philosophers");
	if (data->t2d <= 0)
		exit_with_err("Error: Wrong time to die");
	if (data->t2e <= 0)
		exit_with_err("Error: Wrong time to eat");
	if (data->t2s <= 0)
		exit_with_err("Error: Wrong time to sleep");
	if (ac == 6 && data->must_eat <= 0)
		exit_with_err("Error: Wrong number of times each philosopher must eat");
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (num);
}
