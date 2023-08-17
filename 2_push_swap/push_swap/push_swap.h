/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:44:28 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 13:51:16 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_deque_node
{
	int					value;
	int					idx;
	struct s_deque_node	*next;
	struct s_deque_node	*prev;
}						t_deque_node;

typedef struct s_deque
{
	int					size;
	struct s_deque_node	*node[2];
}						t_deque;

typedef struct s_push_swap
{
	int					sum;
	struct s_deque		a;
	struct s_deque		b;
}						t_push_swap;

enum					e_rear
{
	FRONT = 0,
	REAR = 1
};

typedef struct s_cnt
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					sum;
	int					min[2];
	int					i;
	int					j;
}						t_cnt;

// main.c

void					push_b(t_push_swap *ps);
void					sort(t_push_swap *ps);
void					greedy(t_push_swap *ps);
void					partitioning(t_push_swap *ps, int base);

// deque.c

void					enque(t_deque *st, enum e_rear rear,
							t_deque_node *node);
t_deque_node			*deque(t_deque *st, enum e_rear rear);
int						push(t_deque *from, t_deque *to);
int						swap(t_deque *st);
int						rotate(t_deque *st, enum e_rear rear);

// parse.c

void					parse_arg(t_push_swap *ps, int ac, char *av[]);
t_deque_node			*new_node(int value);
void					set_idx(t_push_swap *ps);
void					set_idx_in_deque(int *arr, t_push_swap *ps);
void					sort_arr(int *arr, t_push_swap *ps);

// utils.c

void					init_ps(t_push_swap *ps);
void					sort_3(t_push_swap *ps);

// checker.c

int						command(t_push_swap *ps, char *cmd);
int						is_sorted(t_push_swap *ps);
void					checker(t_push_swap *ps);

// test.c

void					debug(char *a, t_cnt *cnt);

void					print_deque(t_push_swap *ps);
void					test(t_push_swap *ps);

// command.c

void					sa(t_push_swap *ps);
void					sb(t_push_swap *ps);
void					ss(t_push_swap *ps);
void					pa(t_push_swap *ps);
void					pb(t_push_swap *ps);
void					ra(t_push_swap *ps);
void					rb(t_push_swap *ps);
void					rr(t_push_swap *ps);
void					rra(t_push_swap *ps);
void					rrb(t_push_swap *ps);
void					rrr(t_push_swap *ps);

void					ra_rb(t_push_swap *dup, t_cnt *cnt);
void					ra_rrb(t_push_swap *dup, t_cnt *cnt);
void					rra_rb(t_push_swap *dup, t_cnt *cnt);
void					rra_rrb(t_push_swap *dup, t_cnt *cnt);

t_push_swap				dup_ps(t_push_swap *ps);
void					ra_x(t_push_swap *ps, t_cnt *cnt);
void					rb_x(t_push_swap *ps, t_cnt *cnt);
void					rra_x(t_push_swap *ps, t_cnt *cnt);
void					rrb_x(t_push_swap *ps, t_cnt *cnt);
void					pull_node(t_push_swap *ps);

// min.c

void					init_cnt(t_cnt *cnt);

#endif
