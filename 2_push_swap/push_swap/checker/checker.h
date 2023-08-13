/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:05:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/13 21:20:30 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line/get_next_line.h"
# include "../libft/libft.h"

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
	REAR = 1,
};

int						command(t_push_swap *ps, char *cmd);
void					checker(t_push_swap *ps);

void					enque(t_deque *st, enum e_rear rear,
							t_deque_node *node);
t_deque_node			*deque(t_deque *st, enum e_rear rear);
int						push(t_deque *from, t_deque *to);
int						swap(t_deque *st);
int						rotate(t_deque *st, enum e_rear rear);

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

#endif
