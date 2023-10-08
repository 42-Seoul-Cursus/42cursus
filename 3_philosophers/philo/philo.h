/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/08 16:53:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum	e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}				t_status;

typedef struct	s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				number_of_philosophers;
	int				time_to_die_in_ms;
	int				time_to_eat_in_ms;
	int				time_to_sleep_in_ms;
	int				number_of_times_each_philosopher_must_eat;
	int				cnt;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_status		status;
	int				last_eat_time;
	int				eat_count;
	t_data			*data; // 공유자원
}				t_philo;

// test.c
void	print_philos(t_data *data);

void	exit_with_err(char *err_msg);

void	init_data(t_data *data, int ac, char *av[]);
t_philo	*init_philos(t_data *data);
void	init_philo(t_philo *philo, t_data *data, int id);
void	check_data(t_data *data, int ac);
int	ft_atoi(char *str);

#endif
