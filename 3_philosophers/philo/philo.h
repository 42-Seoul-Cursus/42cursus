/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/03 15:26:57 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct	s_data
{
	int				number_of_philosophers;
	int				time_to_die_in_ms;
	int				time_to_eat_in_ms;
	int				time_to_sleep_in_ms;
	int				number_of_times_each_philosopher_must_eat;
}				t_data;

typedef enum	e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}				t_status;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

#endif
