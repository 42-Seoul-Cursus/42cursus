/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:40:51 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 15:15:21 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg(t_push_swap *ps, int ac, char *av[])
{
	int	i;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = 0;
		while (av[ac] != NULL)
		{
			enque(&ps->a, FRONT, new_node(ft_atoi(av[ac])));
			++ac;
			++ps->sum;
		}
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			enque(&ps->a, FRONT, new_node(ft_atoi(av[i])));
			++i;
			++ps->sum;
		}
	}
	if (is_sorted(ps))
		exit(EXIT_SUCCESS);
}

t_deque_node	*new_node(int value)
{
	t_deque_node	*node;

	node = (t_deque_node *)calloc(1, sizeof(t_deque_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
