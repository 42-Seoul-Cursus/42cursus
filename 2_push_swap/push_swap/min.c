/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:52:24 by seunan            #+#    #+#             */
/*   Updated: 2023/08/16 21:25:38 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cnt(t_cnt *cnt)
{
	cnt->ra = 0;
	cnt->rra = 0;
	cnt->rb = 0;
	cnt->rrb = 0;
	cnt->sum = INT32_MAX;
}

t_push_swap	dup_ps(t_push_swap *ps)
{
	t_push_swap		dup;
	t_deque_node	*tmp;
	t_deque_node	*cur;

	init_ps(&dup);
	cur = ps->a.node[FRONT];
	while (cur != NULL)
	{
		tmp = cur->next;
		enque(&(dup.a), REAR, cur);
		cur = tmp;
	}
	tmp = ps->b.node[FRONT];
	while (cur != NULL)
	{
		tmp = cur->next;
		enque(&(dup.b), REAR, cur);
		cur = tmp;
	}
	dup.sum = ps->sum;
	return (dup);
}

t_cnt	ra_rb(t_push_swap *ps)
{
	t_push_swap	dup;
	t_cnt		cnt;
	int			i;
	int			j;
	int			min[2];

	dup = dup_ps(ps);
	init_cnt(&cnt);
	i = 0;
	while (i < dup.a.size) // ra
	{
		j = 0;
		cnt.rb = 0;
		while (j < dup.b.size) // rb
		{
			if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
				break ;
			rb_x(&dup, &cnt);
			++j;
		}
		if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
			&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
			if (cnt.rb + cnt.ra < cnt.sum)
			{
				min[0] = cnt.ra;
				min[1] = cnt.rb;
				cnt.sum = cnt.ra + cnt.rb;
			}
		while (j-- > 0)
			rrb_x(&dup, 0);
		ra_x(&dup, &cnt);
		++i;
	}
	cnt.ra = min[0];
	cnt.rb = min[1];
	return (cnt);
}

t_cnt	ra_rrb(t_push_swap *ps)
{
	t_push_swap	dup;
	t_cnt		cnt;
	int			i;
	int			j;
	int			min[2];

	dup = dup_ps(ps);
	init_cnt(&cnt);
	i = 0;
	while (i < dup.a.size) // ra
	{
		j = 0;
		cnt.rrb = 0;
		while (j < dup.b.size) // rrb
		{
			if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
				break ;
			rrb_x(&dup, &cnt);
			++j;
		}
		if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
			if (cnt.rrb + cnt.ra < cnt.sum)
			{
				min[0] = cnt.ra;
				min[1] = cnt.rrb;
				cnt.sum = cnt.ra + cnt.rrb;
			}
		while (j-- > 0)
			rb_x(&dup, 0);
		ra_x(&dup, &cnt);
		++i;
	}
	cnt.ra = min[0];
	cnt.rrb = min[1];
	return (cnt);
}

t_cnt	rra_rb(t_push_swap *ps)
{
	t_push_swap	dup;
	t_cnt		cnt;
	int			i;
	int			j;
	int			min[2];

	dup = dup_ps(ps);
	init_cnt(&cnt);
	i = 0;
	while (i < dup.a.size)
	{
		j = 0;
		cnt.rb = 0;
		while (j < dup.b.size)
		{
			if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
				break ;
			rb_x(&dup, &cnt);
			++j;
		}
		if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
			if (cnt.rb + cnt.rra < cnt.sum)
			{
				min[0] = cnt.rra;
				min[1] = cnt.rb;
				cnt.sum = cnt.rra + cnt.rb;
			}
		while (j-- > 0)
			rrb_x(&dup, 0);
		rra_x(&dup, &cnt);
		++i;
	}
	cnt.rra = min[0];
	cnt.rb = min[1];
	return (cnt);
}

t_cnt	rra_rrb(t_push_swap *ps)
{
	t_push_swap	dup;
	t_cnt		cnt;
	int			i;
	int			min[2];
	int			j;

	dup = dup_ps(ps);
	init_cnt(&cnt);
	i = 0;
	while (i < dup.a.size)
	{
		j = 0;
		cnt.rrb = 0;
		while (j < dup.b.size)
		{
			if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
				&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
				break ;
			rrb_x(&dup, &cnt);
			++j;
		}
		if (dup.a.node[FRONT]->idx < dup.b.node[REAR]->idx
			&& dup.b.node[REAR]->idx < dup.a.node[REAR]->idx)
			if (cnt.rrb + cnt.rra < cnt.sum)
			{
				min[0] = cnt.rra;
				min[1] = cnt.rrb;
				cnt.sum = cnt.rra + cnt.rrb;
			}
		while (j-- > 0)
			rb_x(&dup, 0);
		rra_x(&dup, &cnt);
		++i;
	}
	cnt.rra = min[0];
	cnt.rrb = min[1];
	return (cnt);
}
