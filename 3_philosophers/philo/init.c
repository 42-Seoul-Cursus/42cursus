/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/26 18:42:39 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (error(2));
	data->forks = NULL;
	data->num = ft_atoi(av[1]);
	data->t2d = ft_atoi(av[2]);
	data->t2e = ft_atoi(av[3]);
	data->t2s = ft_atoi(av[4]);
	data->must_eat = -2;
	data->dead = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (check_data(data, ac) == 1)
		return (1);
	return (0);
}

int	check_data(t_data *data, int ac)
{
	if (data->num < 1)
		return (error(3));
	if (data->t2d < 1)
		return (error(4));
	if (data->t2e < 1)
		return (error(5));
	if (data->t2s < 1)
		return (error(6));
	if (ac == 6 && data->must_eat < 1)
		return (error(7));
	return (0);
}

void	fail_init_data(pthread_mutex_t **fork, int fail_idx)
{
	int	i;

	i = 0;
	while (i < fail_idx - 1)
	{
		pthread_mutex_destroy(&((*fork)[i]));
		++i;
	}
	free(*fork);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (error(1));
	if (pthread_mutex_init(&(data->lock), NULL) != 0)
	{
		pthread_mutex_destroy(&(data->print));
		return (error(1));
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
	{
		pthread_mutex_destroy(&(data->print));
		pthread_mutex_destroy(&(data->lock));
		return (error(0));
	}
	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
		{
			pthread_mutex_destroy(&(data->print));
			pthread_mutex_destroy(&(data->lock));
			fail_init_data(&(data->forks), i);
			return (error(1));
		}
		++i;
	}
	return (0);
}

void	fail_init_philo(t_philo **philo, int fail_idx)
{
	int	i;

	i = 0;
	while (i < fail_idx - 1)
	{
		pthread_mutex_destroy(&((*philo)[i].lock));
		++i;
	}
	free(*philo);
}

int	init_philo(t_philo **philo, t_data *data)
{
	int			i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num);
	if (!(*philo))
		return (error(0));
	i = 0;
	while (i < data->num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		if (i == data->num - 1)
			(*philo)[i].right_fork = 0;
		else
			(*philo)[i].right_fork = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].is_full = 0;
		(*philo)[i].data = data;
		if (pthread_mutex_init(&((*philo)[i].lock), NULL) != 0)
		{
			fail_init_philo(philo, i);
			return (error(1));
		}
		++i;
	}
	return (0);
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
