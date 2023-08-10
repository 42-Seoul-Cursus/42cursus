/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:44:28 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 23:45:53 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_deque_node
{
	int					value;
	int					idx;
	struct s_deque_node	*next;
	struct s_deque_node	*prev;
}						t_deque_node;

typedef struct s_deque
{
	unsigned int		size;
	struct s_deque_node	*node[2];
}						t_deque;

typedef struct s_push_swap
{
	unsigned int		sum;
	struct s_deque		a;
	struct s_deque		b;
}						t_push_swap;

enum					e_rear
{
	FRONT = 0,
	REAR = 1
};

// main.c

int						command(t_push_swap *ps, char *cmd);

// utils.c

t_deque_node			*new_node(int value);
void					parse_arg(t_push_swap *ps, int ac, char *av[]);

// deque.c

void					enque(t_deque *st, enum e_rear rear,
							t_deque_node *node);
t_deque_node			*deque(t_deque *st, enum e_rear rear);
int						push(t_deque *from, t_deque *to);
int						swap(t_deque *st);
int						rotate(t_deque *st, enum e_rear rear);

// test.c

void					init_ps(t_push_swap *ps);
void					print_deque(t_push_swap *ps);
void					test(t_push_swap *ps);

void					sort_arr(int *arr, t_push_swap *ps);
void					set_idx(t_push_swap *ps);
void					arr_to_deque(int *arr, t_push_swap *ps);

#endif
