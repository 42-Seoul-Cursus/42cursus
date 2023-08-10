/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:40:51 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 18:44:28 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (++i < ac)
	{
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			enque(&ps->a, REAR, new_node(ft_atoi(tmp[j])));
			++j;
			++ps->sum;
		}
	}
}
