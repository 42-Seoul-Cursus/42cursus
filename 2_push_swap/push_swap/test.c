/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:41:36 by seunan            #+#    #+#             */
/*   Updated: 2023/08/16 23:46:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_deque(t_push_swap *ps)

{
	t_deque			*a;
	t_deque			*b;
	t_deque_node	*a_tmp;
	t_deque_node	*b_tmp;
	int				i;

	a = &(ps->a);
	b = &(ps->b);
	a_tmp = a->node[REAR];
	b_tmp = b->node[REAR];
	i = 0;
	while (i < a->size || i < b->size)
	{
		if (i < a->size && a_tmp != NULL)
			printf("\x1b[31m%d\t", a_tmp->value);
		else
			printf("\t");
		if (i < b->size && b_tmp != NULL)
			printf("\x1b[36m%d\n", b_tmp->value);
		else
			printf("\n");
		if (a_tmp == NULL || a_tmp->prev == NULL)
			;
		else
			a_tmp = a_tmp->prev;
		if (b_tmp == NULL || b_tmp->prev == NULL)
			;
		else
			b_tmp = b_tmp->prev;
		++i;
	}
	printf("\x1b[37ma\tb\x1b[0m\n");
}

void	ra_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
	{
		cnt->ra++;
		cnt->sum++;
	}
	rotate(&(ps->a), REAR);
}

void	rb_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
	{
		cnt->rb++;
		cnt->sum++;
	}
	rotate(&(ps->b), REAR);
}

void	rra_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
	{
		cnt->rra++;
		cnt->sum++;
	}
	rotate(&(ps->a), FRONT);
}

void	rrb_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
	{
		cnt->rrb++;
		cnt->sum++;
	}
	rotate(&(ps->b), FRONT);
}

