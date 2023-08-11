/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 21:19:43 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	// test(&ps);
	quick_div_l(&ps, 0);
	return (0);
}

void	sort_3(t_push_swap *ps)
{
	if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
	if (ps->a.node[REAR]->prev->idx > ps->a.node[REAR]->prev->prev->idx)
	{
		rra(ps);
		if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
			sa(ps);
	}
	if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
}

void	quick_div_l(t_push_swap *ps, int base)
{
	ps->pivot_s = ps->a.size / 3;           // 166
	ps->pivot_m = ps->a.size - ps->pivot_s; // 334
	if (ps->a.size == 3)
	{
		sort_3(ps);
	}
	else if (ps->a.size == 2)
	{
		if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
			sa(ps);
	}
	while (ps->a.size > ps->pivot_s + (ps->a.size % 3 == 2))
	{
		if (ps->a.node[REAR]->idx - base >= ps->pivot_m && ps->pivot_m != ps->sum)     // L 334 ~ 500 (167개)
			ra(ps);
		else if (ps->a.node[REAR]->idx - base < ps->pivot_m) // M 167 ~ 333 (167개)
		{
			pb(ps);
			if (ps->b.node[REAR]->idx - base <= ps->pivot_s) // S 1 ~ 166 (166개)
				rb(ps);
		}
	}
	if (ps->a.size > 3)
		quick_div_l(ps, ps->pivot_m + base);
}

// void	quick_join_l(t_push_swap *ps)
// {
// 	return ;
// }
