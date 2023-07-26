/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/26 15:59:53 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack *deque(struct s_stack *st, enum e_rear rear)
{
	struct s_stack_node	*tmp;

	if (st->size == 0)
		return (NULL);
	tmp = st->node[rear];
	if (st->size == 1)
	{
		st->node[rear] = NULL;
		st->node[rear]->next = NULL;
		st->node[rear]->prev = NULL;
	}
	else
	{
		st->node[rear] = st->node[rear]->next;
		st->node[rear]->prev = NULL;
		tmp->next = NULL;
	}
	st->size--;
	return (tmp);
}

void	enque(struct s_stack *st, enum e_rear rear)
{
	struct s_stack_node	*tmp;

	tmp = st->node[rear];
	if (st->size == 0)
	{
		st->node[rear] = tmp;
		st->node[rear]->next = NULL;
		st->node[rear]->prev = NULL;
	}
	else
	{
		st->node[rear] = tmp;
		st->node[rear]->next = tmp;
		st->node[rear]->prev = NULL;
	}
	st->size++;
}

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;
	ft_printf("Hello, world!\n");
	return (0);
}

