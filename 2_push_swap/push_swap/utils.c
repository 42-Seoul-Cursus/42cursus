/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:09:06 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 23:01:39 by seunan           ###   ########.fr       */
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

void	partitioning(t_push_swap *ps)
{
	if (ps->a.size <= 3)
	{
		if (ps->a.size == 3)
			sort_3(ps);
		else if (ps->a.size == 2 && ps->a.node[FRONT]->idx < ps->a.node[REAR]->idx)
			sa(ps);
		exit(EXIT_SUCCESS);
	}
	ps->pivot[0] = ps->a.size / 3;  // 3
	ps->pivot[1] = ps->a.size - ps->pivot[0]; // 6
	while (ps->a.size > ps->pivot[0])
	{
		if (ps->a.node[REAR]->idx > ps->pivot[1])       // L 7 ~ 9
			ra(ps);
		else if (ps->a.node[REAR]->idx <= ps->pivot[1]) // M 4 ~ 6
		{
			pb(ps);
			if (ps->b.node[REAR]->idx <= ps->pivot[0])  // S 1 ~ 3
				rb(ps);
		}
	}
	while (ps->a.size)
		pb(ps);
}

void	sort_3(t_push_swap *ps)
{
	int	top;
	int	mid;
	int	bot;

	top = ps->a.node[REAR]->idx;
	mid = ps->a.node[REAR]->prev->idx;
	bot = ps->a.node[REAR]->prev->prev->idx;
	if (top > mid && mid > bot) // 3 2 1 top -> bot
	{
		sa(ps);
		rra(ps);
	}
	else if (top > mid && mid < bot && top > bot) // 3 1 2
		ra(ps);
	else if (top > mid && mid < bot && top < bot) // 2 1 3
		sa(ps);
	else if (top < mid && mid > bot && top > bot) // 2 3 1
		rra(ps);
	else if (top < mid && mid > bot && top < bot) // 1 3 2
	{
		sa(ps);
		ra(ps);
	}
}
