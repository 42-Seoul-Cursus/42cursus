/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:44:28 by seunan            #+#    #+#             */
/*   Updated: 2023/07/26 15:59:34 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

struct					s_stack_node
{
	int					value;
	int					idx;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
};

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
	BACK = 1
};

#endif
