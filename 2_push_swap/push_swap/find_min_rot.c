/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:52:24 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 05:05:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cnt(t_cnt *cnt)
{
	cnt->ra = 0;
	cnt->rra = 0;
	cnt->rb = 0;
	cnt->rrb = 0;
	cnt->min[0] = 0;
	cnt->min[1] = 0;
	cnt->i = 0;
	cnt->j = 0;
	cnt->sum = INT32_MAX;
}

void	debug(char *a, t_cnt *cnt)
{
	printf("%s\nra : %d\nrb : %d\nrra : %d\nrrb : %d\nsum : %d\n",
	a, cnt->ra, cnt->rb, cnt->rra, cnt->rrb, cnt->sum);
}

void	ra_rb(t_push_swap *dup, t_cnt *cnt)
{
	init_cnt(cnt);
	while (cnt->i < dup->a.size)
	{
		cnt->j = 0;
		cnt->rb = 0;
		while (cnt->j < dup->b.size)
		{
			if (dup->b.node[REAR]->idx < dup->a.node[REAR]->idx
				&& (dup->a.node[FRONT]->idx < dup->b.node[REAR]->idx
				|| dup->a.node[FRONT]->idx == dup->sum)
				&& cnt->rb + cnt->ra < cnt->sum)
			{
				cnt->min[0] = cnt->ra;
				cnt->min[1] = cnt->rb;
				cnt->sum = cnt->ra + cnt->rb;
			}
			rb_x(dup, cnt);
			++cnt->j;
		}
		while (cnt->j-- > 0)
			rrb_x(dup, 0);
		ra_x(dup, cnt);
		++cnt->i;
	}
	cnt->ra = cnt->min[0];
	cnt->rb = cnt->min[1];
}

void	ra_rrb(t_push_swap *dup, t_cnt *cnt)
{
	init_cnt(cnt);
	while (cnt->i < dup->a.size)
	{
		cnt->j = 0;
		cnt->rrb = 0;
		while (cnt->j < dup->b.size)
		{
			if (dup->b.node[REAR]->idx < dup->a.node[REAR]->idx
				&& (dup->a.node[FRONT]->idx < dup->b.node[REAR]->idx
				|| dup->a.node[FRONT]->idx == dup->sum)
				&& cnt->rrb + cnt->ra < cnt->sum)
			{
				cnt->min[0] = cnt->ra;
				cnt->min[1] = cnt->rrb;
				cnt->sum = cnt->ra + cnt->rrb;
			}
			rrb_x(dup, cnt);
			++cnt->j;
		}
		while (cnt->j-- > 0)
			rb_x(dup, 0);
		ra_x(dup, cnt);
		++cnt->i;
	}
	cnt->ra = cnt->min[0];
	cnt->rrb = cnt->min[1];
}

void	rra_rb(t_push_swap *dup, t_cnt *cnt)
{
	init_cnt(cnt);
	while (cnt->i < dup->a.size)
	{
		cnt->j = 0;
		cnt->rb = 0;
		while (cnt->j < dup->b.size)
		{
			if (dup->b.node[REAR]->idx < dup->a.node[REAR]->idx
				&& (dup->a.node[FRONT]->idx < dup->b.node[REAR]->idx
				|| dup->a.node[FRONT]->idx == dup->sum)
				&& cnt->rb + cnt->rra < cnt->sum)
			{
				cnt->min[0] = cnt->rra;
				cnt->min[1] = cnt->rb;
				cnt->sum = cnt->rra + cnt->rb;
			}
			rb_x(dup, cnt);
			++cnt->j;
		}
		while (cnt->j-- > 0)
			rrb_x(dup, 0);
		rra_x(dup, cnt);
		++cnt->i;
	}
	cnt->rra = cnt->min[0];
	cnt->rb = cnt->min[1];
}

void	rra_rrb(t_push_swap *dup, t_cnt *cnt)
{
	init_cnt(cnt);
	while (cnt->i < dup->a.size)
	{
		cnt->j = 0;
		cnt->rrb = 0;
		while (cnt->j < dup->b.size)
		{
			if (dup->b.node[REAR]->idx < dup->a.node[REAR]->idx
				&& (dup->a.node[FRONT]->idx < dup->b.node[REAR]->idx
				|| dup->a.node[FRONT]->idx == dup->sum)
				&& cnt->rrb + cnt->rra < cnt->sum)
			{
				cnt->min[0] = cnt->rra;
				cnt->min[1] = cnt->rrb;
				cnt->sum = cnt->rra + cnt->rrb;
			}
			rrb_x(dup, cnt);
			++cnt->j;
		}
		while (cnt->j-- > 0)
			rb_x(dup, 0);
		rra_x(dup, cnt);
		++cnt->i;
	}
	cnt->rra = cnt->min[0];
	cnt->rrb = cnt->min[1];
}
