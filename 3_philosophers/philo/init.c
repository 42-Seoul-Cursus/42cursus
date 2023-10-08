/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/08 19:25:39 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int ac, char *av[])
{
	int	i;

	if (!(ac == 5 || ac == 6))
		exit_with_err("Error: Wrong number of arguments");
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die_in_ms = ft_atoi(av[2]);
	data->time_to_eat_in_ms = ft_atoi(av[3]);
	data->time_to_sleep_in_ms = ft_atoi(av[4]);
	data->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	data->cnt = 0;
	if (pthread_mutex_init(&(data->print), NULL) != 0)
		exit_with_err("Mutex initialization failed");
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->forks)
		exit_with_err("Malloc failed");
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			exit_with_err("Mutex initialization failed");
		++i;
	}
}
t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int	i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!philos)
		exit_with_err("Malloc failed");
	while (i < data->number_of_philosophers)
	{
		init_philo(&philos[i], data, i);
		i++;
	}
	return (philos);
}
// 0 1 2 3 4
// 4 3 2 1 0
void	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id + 1;
	philo->status = THINKING;
	philo->right_fork = id; // 4
	if (id == data->number_of_philosophers - 1)
		philo->left_fork = 0;
	else
		philo->left_fork = id + 1; // 2
	philo->data = data;
}

void	check_data(t_data *data, int ac)
{
	if (data->number_of_philosophers < 2)
		exit_with_err("Error: Wrong number of philosophers");
	if (data->time_to_die_in_ms <= 0)
		exit_with_err("Error: Wrong time to die");
	if (data->time_to_eat_in_ms <= 0)
		exit_with_err("Error: Wrong time to eat");
	if (data->time_to_sleep_in_ms <= 0)
		exit_with_err("Error: Wrong time to sleep");
	if (ac == 6 && data->number_of_times_each_philosopher_must_eat <= 0)
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
