/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:44:28 by seunan            #+#    #+#             */
/*   Updated: 2023/07/28 19:25:44 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack_node
{
	int					value;
	int					idx;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_stack
{
	unsigned int		size;
	struct s_stack_node	*node[2];
}						t_stack;

typedef struct s_push_swap
{
	unsigned int		cnt;
	struct s_stack		a;
	struct s_stack		b;
}						t_push_swap;

enum					e_rear
{
	FRONT = 0,
	REAR = 1
};

int						push(struct s_stack *from, struct s_stack *to);
int						swap(t_stack *st);
int						rotate(t_stack *st, enum e_rear rear);
t_stack					*deque(struct s_stack *st, enum e_rear rear);
void					enque(struct s_stack *st, enum e_rear rear,
							struct s_stack_node *node);
void					print_stack(t_stack *st);
void					parse_arg(t_push_swap *ps, int ac, char *av[]);
t_stack_node			*new_node(int value);

#endif
