/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/23 13:15:23 by seunan           ###   ########.fr       */
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
}			t_bool;

typedef struct s_data
{
	pthread_mutex_t		*forks;		 // forks in the table
	pthread_mutex_t		print;		 // before use printf
	pthread_mutex_t		lock;		 // before accessing 'dead' in shared data
	int					num;		 // number of philosophers                    (only read)
	int					t2d;		 // time to die                               (only read)
	int					t2e;		 // time to eat                               (only read)
	int					t2s;		 // time to sleep                             (only read)
	int					must_eat;	 // number of times each philosopher must eat (only read)
	char				dead;		 // if one of the philosophers dies, it becomes 1
	struct timeval		start_time;	 // philo routine start time                  (only read)
}						t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					left_fork; // fork on the left (index)
	int					right_fork; // fork on the right (index)
	int					eat_cnt; // number of times the philosopher ate
	int					is_full; // if must_eat is set, it becomes 1 when eat_cnt is equal to must_eat
	struct timeval		last_eat; // last time the philosopher ate
	t_data				*data; // shared data
}						t_philo;

// test.c
void			print_philos(t_philo *philos);

// print.c
void			print_timestamp(t_philo *philo, char *s, int is_eating);
void			print_success(t_philo *philo);
void			print_dead(t_philo *philo, struct timeval cur);
void			exit_with_err(char *err_msg);

// init.c
void			init_data(t_data *data, int ac, char *av[]);
void			check_data(t_data *data, int ac);
void			init_mutex(t_data *data);
t_philo			*init_philo(t_data *data);
int				ft_atoi(char *str);

// utils.c

int				spend_time(t_philo *philo, unsigned int us);
unsigned int	get_us(struct timeval cur, struct timeval start);
void			print_timestamp(t_philo *philo, char *s, int is_eating);
int				is_dead(t_data *data);

#endif
