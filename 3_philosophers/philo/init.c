/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/24 19:46:33 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		exit_with_err("Usage: ./philo num t2d t2e t2s [must_eat]");
	data->num = ft_atoi(av[1]);
	data->t2d = ft_atoi(av[2]);
	data->t2e = ft_atoi(av[3]);
	data->t2s = ft_atoi(av[4]);
	data->must_eat = -2;
	data->dead = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
}

void	check_data(t_data *data, int ac)
{
	if (data->num < 1)
		exit_with_err("Invalid value number of philosophers");
	if (data->t2d <= 0)
		exit_with_err("Invalid value time to die");
	if (data->t2e <= 0)
		exit_with_err("Invalid value time to eat");
	if (data->t2s <= 0)
		exit_with_err("Invalid value time to sleep");
	if (ac == 6 && data->must_eat <= 0)
		exit_with_err("Invalid value number of times each philo must eat");
}

void	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->print), NULL) != 0)
		exit_with_err("Failed print mutex initialization");
	if (pthread_mutex_init(&(data->lock), NULL) != 0)
		exit_with_err("Failed lock mutex initialization");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		exit_with_err("Failed forks arr malloc");
	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			exit_with_err("Failed forks mutex initialization");
		++i;
	}
}

t_philo	*init_philo(t_data *data)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num);
	if (!philo)
		exit_with_err("Failed philo arr malloc");
	i = 0;
	while (i < data->num)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		if (i == data->num - 1)
			philo[i].right_fork = 0;
		else
			philo[i].right_fork = i + 1;
		philo[i].eat_cnt = 0;
		philo[i].is_full = 0;
		philo[i].data = data;
		if (pthread_mutex_init(&(philo[i].lock), NULL) != 0)
			exit_with_err("Failed forks mutex initialization");
		++i;
	}
	return (philo);
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
		if (num < 0)
			return (-1);
		str++;
	}
	return (num);
}
