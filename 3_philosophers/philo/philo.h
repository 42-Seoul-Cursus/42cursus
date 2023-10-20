/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/20 23:27:00 by seunan           ###   ########.fr       */
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

typedef struct s_data
{
	pthread_mutex_t		*forks;		 // forks in the table
	pthread_mutex_t		print;		 // before use printf
	pthread_mutex_t		lock;		 // before accessing shared data
	int					num;		 // number of philosophers                    (only read)
	int					t2d;		 // time to die                               (only read)
	int					t2e;		 // time to eat                               (only read)
	int					t2s;		 // time to sleep                             (only read)
	int					must_eat;	 // number of times each philosopher must eat (only read)
	short				dead;		 // if one of the philosophers dies, it becomes 1
	struct timeval		start_time;	 // philo routine start time                  (only read)
}						t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					left_fork; // fork on the left (index)
	int					right_fork; // fork on the right (index)
	struct timeval		last_eat;
	int					eat_cnt;
	int					is_full;
	t_data				*data; // shared data
}						t_philo;

// test.c
void					print_philos(t_philo *philos);

void					exit_with_err(char *err_msg);

void					init_data(t_data *data, int ac, char *av[]);
t_philo					*init_philos(t_data *data);
void					init_philo(t_philo *philo, t_data *data, int id);
void					check_data(t_data *data, int ac);
int						ft_atoi(char *str);
void					*philo_routine(void *arg);

#endif
