/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/21 22:01:41 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_us(struct timeval start, struct timeval cur)
{
	return ((cur.tv_sec - start.tv_sec) * 1000000
		+ (cur.tv_usec - start.tv_usec));
}

void	print_time(t_philo *philo, char *s, int is_eating)
{
	struct timeval	cur;

	if (is_eating == 1)
	{
		pthread_mutex_lock(&(philo->data->print));
		gettimeofday(&(philo->last_eat), NULL);
		printf("%u %d %s\n", get_us(philo->data->start_time, philo->last_eat) / 1000, philo->id, s);
	}
	else
	{
		pthread_mutex_lock(&philo->data->print);
		gettimeofday(&cur, NULL);
		printf("%u %d %s\n", get_us(philo->data->start_time, cur) / 1000, philo->id, s);
	}
	pthread_mutex_unlock(&philo->data->print);
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

int	spend_time(t_philo *philo, unsigned int time)
{
	struct timeval	start;
	struct timeval	cur;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&cur, NULL);
		if (is_dead(philo->data))
			return (1);
		if (get_us(start, cur) >= time)
			return (0);
		usleep(100);
	}
	return (1);
}

int	print_eat(t_philo *philo)
{
	if (is_dead(philo->data))
		return (1);
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&(philo->last_eat), NULL);
	printf("%u %d is eating\n", get_us(philo->data->start_time, philo->last_eat) / 1000, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->data->lock);
	if (spend_time(philo ,philo->data->t2e * 1000) == 1)
		return (1);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	struct timeval	cur;

	if (is_dead(philo->data))
		return (1);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&cur, NULL);
	printf("%d %d has taken a fork\n", get_us(philo->data->start_time, cur) / 1000, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
int	take_left_fork(t_philo *philo)
{
	struct timeval	cur;

	if (is_dead(philo->data))
		return (1);
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&cur, NULL);
	printf("%d %d has taken a fork\n", get_us(philo->data->start_time, cur) / 1000, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

int	sleeping(t_philo *philo)
{
	struct timeval	cur;

	if (is_dead(philo->data))
		return (1);
	pthread_mutex_lock(&philo->data->print);
	gettimeofday(&cur, NULL);
	printf("%d %d is sleeping\n", get_us(philo->data->start_time, cur) / 1000, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	if (spend_time(philo ,philo->data->t2s * 1000) == 1)
		return (1);
	return (0);
}

int	eat_odd(t_philo *philo)
{
	if (take_right_fork(philo) == 1)
		return (1);
	print_eat(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	return (0);
}

int	eat_even(t_philo *philo)
{
	if (take_left_fork(philo) == 1)
		return (1);
	print_eat(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	return (0);
}

int	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (take_right_fork(philo) == 1)
			return (1);
	}
	else
	{
		if (take_left_fork(philo) == 1)
			return (1);
	}
	if (philo->id % 2 == 0)
	{
		if (eat_even(philo) == 1)
			return (1);
	}
	else
	{
		if (eat_odd(philo) == 1)
			return (1);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(100);
	else
	{
		pthread_mutex_lock(&data->print);
		gettimeofday(&data->start_time, NULL);
		pthread_mutex_unlock(&data->print);
	}
	while (1)
	{
		if (eating(philo) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

void	make_thread(t_philo *philos)
{
	int				i;
	int				cnt;
	struct timeval	cur;

	i = 0;
	while (i < philos->data->num)
	{
		pthread_create(&(philos[i].thread), NULL, philo_routine, &(philos[i]));
		++i;
	}
	i = 0;
	cnt = 0;
	spend_time(philos, philos->data->t2d * 1000); // 먹을 때 시간을 체크하므로, 죽는 시간을 체크하기 위해선 먹는 시간을 기다려야 함
	while (1)
	{
		if (i == philos->data->num)
			i = 0;
		gettimeofday(&cur, NULL);
		pthread_mutex_lock(&(philos->data->lock));
		if ((cur.tv_sec - philos[i].last_eat.tv_sec) * 1000 + (cur.tv_usec - philos[i].last_eat.tv_usec) / 1000 >= philos->data->t2d)
		{
			philos->data->dead = 1;
			pthread_mutex_lock(&(philos->data->print));
			printf("%ld %d died\n", (cur.tv_sec - philos[i].data->start_time.tv_sec) * 1000 + (cur.tv_usec - philos[i].data->start_time.tv_usec) / 1000, philos[i].id);
			pthread_mutex_unlock(&(philos->data->print));
			pthread_mutex_unlock(&(philos->data->lock));
			break;
		}
		pthread_mutex_unlock(&(philos->data->lock));
		if (philos->data->must_eat != -2 && philos[i].eat_cnt >= philos->data->must_eat)
		{
			if (philos[i].is_full == 0)
			{
				philos[i].is_full = 1;
				++cnt;
			}
			if (cnt == philos->data->num)
			{
				pthread_mutex_lock(&(philos->data->lock));
				philos->data->dead = 1;
				pthread_mutex_unlock(&(philos->data->lock));
				pthread_mutex_lock(&(philos->data->print));
				printf("\033[32m");
				printf("All philos ate %d times\n", philos->data->must_eat);
				printf("\033[0m");
				pthread_mutex_unlock(&(philos->data->print));
				break;
			}
		}
		++i;
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
	init_mutex(&data);
	philo = init_philo(&data);
	// print_philos(philo);
	make_thread(philo);
	return (0);
}
