/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:44:28 by seunan            #+#    #+#             */
/*   Updated: 2023/07/27 17:18:39 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack_node
{
	int value; // 실제값
	int idx;   // 들어온 순서
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_stack
{
	unsigned int size;            // 현재 스택의 크기
	struct s_stack_node *node[2]; // 스택의 앞, 뒤
}						t_stack;

typedef struct s_push_swap
{
	unsigned int cnt; // 두 스택의 크기
	struct s_stack		a;
	struct s_stack		b;
}						t_push_swap;

enum					e_rear
{
	FRONT = 0,
	BACK = 1
};

int						push(struct s_stack *from, struct s_stack *to);
int						swap(t_stack *st);
int						rotate(t_stack *st, enum e_rear rear);
struct s_stack			*deque(struct s_stack *st, enum e_rear rear);
void					enque(struct s_stack *st, enum e_rear rear,
							struct s_stack_node *node);
void					print_stack(t_stack *st);
void					parse_arg(t_push_swap *ps, int ac, char *av[]);

#endif
