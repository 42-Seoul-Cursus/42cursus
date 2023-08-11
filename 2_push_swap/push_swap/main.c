/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 17:04:27 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	// test(&ps);
	quick_sort(&ps);
	return (0);
}

void	sort_3(t_push_swap *ps)
{
	if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
	if (ps->a.node[REAR]->prev->idx > ps->a.node[REAR]->prev->prev->idx)
	{
		rra(ps);
		sa(ps);
	}
	if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
}

// 334 ~ 499 (0 ~ 165)
void	quick_sort_l(t_push_swap *ps)
{
	unsigned int pivot_s;
	unsigned int pivot_m;

	pivot_s = ps->a.size / 3; // 55
	pivot_m = ps->a.size * 2 / 3; // 111
	while (ps->a.size > pivot_s)
	{
		if (ps->a.node[REAR]->idx - 334 > pivot_m) // L 112 ~ 165 (54개)
			ra(ps); // a 바닥으로
		else if (ps->a.node[REAR]->idx - 334 <= pivot_m) // M 56 ~ 111 (56개)
		{
			pb(ps); // b의 top으로 옮김
			if (ps->b.node[REAR]->idx - 334  <= pivot_s) // S 0 ~ 55 (56개)
				rb(ps); // b 바닥으로
		}
	}
	// if (ps->a.size > 3)
	// 	quick_sort_l(ps);
}

void	quick_sort(t_push_swap *ps)
{
	unsigned int pivot_s;
	unsigned int pivot_m;

	pivot_s = ps->a.size / 3; // 166
	pivot_m = ps->a.size * 2 / 3; // 333
	while (ps->a.size > pivot_s)
	{
		if (ps->a.node[REAR]->idx > pivot_m) // L 334 ~ 499 (166개)
			ra(ps); // a 바닥으로
		else if (ps->a.node[REAR]->idx <= pivot_m) // M 167 ~ 333 (167개)
		{
			pb(ps); // b의 top으로 옮김
			if (ps->b.node[REAR]->idx <= pivot_s) // S 0 ~ 166 (167개)
				rb(ps); // b 바닥으로
		}
	}
	quick_sort_l(ps);
}
