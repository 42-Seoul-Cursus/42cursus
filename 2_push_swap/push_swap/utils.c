/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:09:06 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 13:51:01 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_push_swap *ps, int base)
{
	int	pivot[2];

	pivot[0] = ps->a.size / 3;
	pivot[1] = ps->a.size - pivot[0];
	while (ps->a.size > pivot[0])
	{
		if (ps->a.node[REAR]->idx > pivot[1] + base)
			ra(ps);
		else if (ps->a.node[REAR]->idx <= pivot[1] + base)
		{
			pb(ps);
			if (ps->b.node[REAR]->idx <= pivot[0] + base)
				rb(ps);
		}
	}
	if (ps->a.size > 3 && base <= ps->sum)
		partitioning(ps, pivot[1] + base);
	if (ps->a.size == 3)
		sort_3(ps);
	if (ps->a.size == 2 && ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
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
