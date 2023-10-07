/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/07 15:10:57 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int ac, char *av[])
{
	if (!(ac == 5 || ac == 6))
		exit_with_err("Error: Wrong number of arguments");
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die_in_ms = ft_atoi(av[2]);
	data->time_to_eat_in_ms = ft_atoi(av[3]);
	data->time_to_sleep_in_ms = ft_atoi(av[4]);
	data->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->status = THINKING;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
}

void	check_data(t_data *data, int ac)
{
	int	i;

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
	data->philos = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!data->philos)
		exit_with_err("Error: Malloc failed");
	i = 1;
	while (i <= data->number_of_philosophers)
	{
		init_philo(&data->philos[i], i);
		i++;
	}
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
