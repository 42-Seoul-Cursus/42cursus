/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/18 16:09:22 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}						t_status;

typedef struct s_data
{
	pthread_mutex_t		*forks; // forks in the table
	pthread_mutex_t		print; // print lock
	unsigned int		num; // number of philosophers
	unsigned int		t2d; // time to die
	unsigned int		t2e; // time to eat
	unsigned int		t2s; // time to sleep
	unsigned int		must_eat; // number of times each philosopher must eat
	struct timeval		start_time; // philo routine start time
}						t_data;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	t_status			status;
	unsigned int		left_fork; // fork on the left (index)
	unsigned int		right_fork; // fork on the right (index)
	unsigned int		last_eat;
	t_data				*data; // shared data
}						t_philo;

// test.c
void					print_philos(t_philo *philos);

void					exit_with_err(char *err_msg);

void					init_data(t_data *data, int ac, char *av[]);
t_philo					*init_philos(t_data *data);
void					init_philo(t_philo *philo, t_data *data, unsigned int id);
void					check_data(t_data *data, int ac);
int						ft_atoi(char *str);
void					*philo_routine(void *arg);

#endif
