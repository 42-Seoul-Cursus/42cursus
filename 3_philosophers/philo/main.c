/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/20 18:34:41 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 100us씩 쪽잠을 자서 time (ms) 만큼 시간을 보내는 함수 == usleep(time * 1000)
int	spend_time(t_philo *philo, unsigned int time)
{
	struct timeval	cur;
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (1)
	{
		pthread_mutex_lock(&(philo->data->lock));
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&(philo->data->lock));
			return (1);
		}
		pthread_mutex_unlock(&(philo->data->lock));
		gettimeofday(&cur, NULL);
		if ((cur.tv_sec - start.tv_sec) * 1000000 + (cur.tv_usec - start.tv_usec) >= time)
			return (0);
		usleep(100);
	}
	return (0);
}

void	print_eat(t_philo *philo)
{
	unsigned int	time;

	gettimeofday(&(philo->last_eat), NULL);
	// 읽기만 하므로 lock 필요 없음
	time = (philo->last_eat.tv_sec - philo->data->start_time.tv_sec) * 1000 + (philo->last_eat.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&(philo->data->lock));
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->lock));
	pthread_mutex_lock(&philo->data->print);
	printf("%d %d is eating\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	spend_time(philo ,philo->data->t2e * 1000);
}

void	take_right_fork(t_philo *philo)
{
	struct timeval	cur;
	unsigned int	time;

	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	gettimeofday(&cur, NULL);
	time = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&(philo->data->lock));
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->lock));
	pthread_mutex_lock(&philo->data->print);
	printf("%d %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}
void	take_left_fork(t_philo *philo)
{
	struct timeval	cur;
	unsigned int	time;

	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	gettimeofday(&cur, NULL);
	time = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&(philo->data->lock));
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->lock));
	pthread_mutex_lock(&philo->data->print);
	printf("%d %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	sleeping(t_philo *philo)
{
	struct timeval	cur;
	unsigned int	time;

	gettimeofday(&cur, NULL);
	time = (cur.tv_sec - philo->data->start_time.tv_sec) * 1000 + (cur.tv_usec - philo->data->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&(philo->data->lock));
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->lock));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->lock));
	pthread_mutex_lock(&philo->data->print);
	printf("%d %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	spend_time(philo ,philo->data->t2s * 1000);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		take_right_fork(philo);
	else
		take_left_fork(philo);
	if (philo->id % 2 == 0)
	{
		take_left_fork(philo);
		print_eat(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	}
	else
	{
		take_right_fork(philo);
		print_eat(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
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
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&(philo->data->lock));
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&(philo->data->lock));
			return (NULL);
		}
		pthread_mutex_unlock(&(philo->data->lock));
	}
	return (NULL);
}

void	make_thread(t_philo *philos)
{
	int				i;
	struct timeval	cur;

	i = 0;
	while (i < philos->data->num)
	{
		pthread_create(&(philos[i].thread), NULL, philo_routine, &(philos[i]));
		++i;
	}
	i = 0;
	spend_time(philos, philos->data->t2d * 1000);
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
	philo = init_philos(&data);
	// print_philos(philo);
	make_thread(philo);
	return (0);
}
