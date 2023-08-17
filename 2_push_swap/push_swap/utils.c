/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:09:06 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 15:15:14 by seunan           ###   ########.fr       */
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

void	sort_3(t_push_swap *ps)
{
	int	top;
	int	mid;
	int	bot;

	top = ps->a.node[REAR]->idx;
	mid = ps->a.node[REAR]->prev->idx;
	bot = ps->a.node[REAR]->prev->prev->idx;
	if (top > mid && mid > bot)
	{
		sa(ps);
		rra(ps);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(ps);
	else if (top > mid && mid < bot && top < bot)
		sa(ps);
	else if (top < mid && mid > bot && top > bot)
		rra(ps);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(ps);
		ra(ps);
	}
}

void	push_b(t_push_swap *ps)
{
	while (ps->a.size > 3)
	{
		if (ps->a.node[REAR]->idx == ps->sum)
			ra(ps);
		else
			pb(ps);
	}
	sort_3(ps);
	if (ps->b.size > 0)
		greedy(ps);
}

int	is_sorted(t_push_swap *ps)
{
	t_deque_node	*cur;
	t_deque_node	*tmp;

	cur = ps->a.node[FRONT];
	while (cur->next != NULL)
	{
		tmp = cur->next;
		if (cur->value < tmp->value)
			return (0);
		cur = tmp;
	}
	return (1);
}

void	assign_min(t_cnt *cnt, int a, int b)
{
	cnt->min[0] = a;
	cnt->min[1] = b;
	cnt->sum = a + b;
}
