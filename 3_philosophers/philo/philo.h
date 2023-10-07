/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/07 15:12:17 by seunan           ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_status		status;
	int				last_eat_time;
	int				eat_count;
}				t_philo;


typedef struct	s_data
{
	t_philo			*philos;
	int				number_of_philosophers;
	int				time_to_die_in_ms;
	int				time_to_eat_in_ms;
	int				time_to_sleep_in_ms;
	int				number_of_times_each_philosopher_must_eat;
}				t_data;

// test.c
void	print_philos(t_data *data);

void	exit_with_err(char *err_msg);

void	init_data(t_data *data, int ac, char *av[]);
void	init_philo(t_philo *philo, int id);
void	check_data(t_data *data, int ac);
int		ft_atoi(char *str);

#endif
