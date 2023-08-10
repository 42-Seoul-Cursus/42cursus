/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:40:51 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 23:33:40 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_push_swap *ps)
{
	ps->a.size = 0;
	ps->a.node[FRONT] = NULL;
	ps->a.node[REAR] = NULL;
	ps->b.size = 0;
	ps->b.node[FRONT] = NULL;
	ps->b.node[REAR] = NULL;
	ps->sum = 0;
}

t_deque_node	*new_node(int value)
{
	t_deque_node	*node;

	node = (t_deque_node *)malloc(sizeof(t_deque_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	parse_arg(t_push_swap *ps, int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		enque(&ps->a, REAR, new_node(ft_atoi(av[i])));
		++i;
		++ps->sum;
	}
	set_idx(ps);
}
