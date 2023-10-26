/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/26 13:46:17 by seunan           ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	int				num;
	int				t2d;
	int				t2e;
	int				t2s;
	int				must_eat;
	char			dead;
	struct timeval	start_time;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	lock;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	int				is_full;
	struct timeval	last_eat;
	t_data			*data;
}					t_philo;

// main.c
void				free_data(t_philo **philo);

// init.c
void				init_data(t_data *data, int ac, char *av[]);
void				check_data(t_data *data, int ac);
void				init_mutex(t_data *data);
t_philo				*init_philo(t_data *data);
int					ft_atoi(char *str);

//monitor.c
void				make_thread(t_philo *philo);
void				monitoring(t_philo *philo);
int					check_dead(t_philo *philo, int i);
int					check_must_eat(t_philo *philo, int i, int *cnt);
void				join_philo(t_philo *philo);

// routine.c
void				*philo_routine(void *arg);
int					eating(t_philo *philo);
int					lets_eat(t_philo *philo);
int					sleeping(t_philo *philo);
int					thinking(t_philo *philo);

// print.c
int					print_timestamp(t_philo *philo, char *s);
int					print_timestamp_eat(t_philo *philo);
void				print_success(t_philo *philo);
void				print_dead(t_philo *philo, struct timeval cur);
void				exit_with_err(char *err_msg);

// utils.c
int					spend_time(t_philo *philo, int ms);
unsigned long long	get_ms(struct timeval cur, struct timeval start);
int					is_dead(t_data *data);
int					take_two_fork(t_philo *philo);

#endif
