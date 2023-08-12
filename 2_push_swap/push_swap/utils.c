/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:09:06 by seunan            #+#    #+#             */
/*   Updated: 2023/08/12 16:36:40 by seunan           ###   ########.fr       */
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
