/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/16 21:28:58 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	sort(&ps);
	t_push_swap dup = dup_ps(&ps);
	print_deque(&ps);
	print_deque(&dup);
	return (0);
}

void	deque_rot(t_push_swap *ps, t_cnt cnt)
{
	while (cnt.ra-- > 0)
		ra(ps);
	while (cnt.rra-- > 0)
		rra(ps);
	while (cnt.rb-- > 0)
		rb(ps);
	while (cnt.rrb-- > 0)
		rrb(ps);
	pa(ps);
}

void	greedy(t_push_swap *ps)
{
	t_cnt	cnt;

	while (ps->b.size > 0)
	{
		init_cnt(&cnt);
		if (cnt.sum > ra_rb(ps).sum)
		{
			cnt = ra_rb(ps);
		printf("cnt.ra : %d\ncnt.rra : %d\ncnt.rb : %d\ncnt.rrb : %d\ncnt.sum : %d\n", cnt.ra, cnt.rra, cnt.rb, cnt.rrb, cnt.sum);

		}
		if (cnt.sum > ra_rrb(ps).sum)
		{
			cnt = ra_rrb(ps);
		printf("cnt.ra : %d\ncnt.rra : %d\ncnt.rb : %d\ncnt.rrb : %d\ncnt.sum : %d\n", cnt.ra, cnt.rra, cnt.rb, cnt.rrb, cnt.sum);

		}
		if (cnt.sum > rra_rb(ps).sum)
		{
			cnt = rra_rb(ps);
		printf("cnt.ra : %d\ncnt.rra : %d\ncnt.rb : %d\ncnt.rrb : %d\ncnt.sum : %d\n", cnt.ra, cnt.rra, cnt.rb, cnt.rrb, cnt.sum);

		}
		if (cnt.sum > rra_rrb(ps).sum)
		{
			cnt = rra_rrb(ps);
		printf("cnt.ra : %d\ncnt.rra : %d\ncnt.rb : %d\ncnt.rrb : %d\ncnt.sum : %d\n", cnt.ra, cnt.rra, cnt.rb, cnt.rrb, cnt.sum);

		}
		deque_rot(ps, cnt);
	}
}

void	sort(t_push_swap *ps)
{
	if (ps->a.size == 2 && ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
	else if (ps->a.size == 3)
		sort_3(ps);
	else if (ps->a.size > 3)
	{
		partitioning(ps, 0);
		ps->a.node[FRONT]->idx = 0;
		// greedy(ps);
	}
}

void	partitioning(t_push_swap *ps, int base)
{
	int	pivot[2];

	pivot[0] = ps->a.size / 3;        // 33
	pivot[1] = ps->a.size - pivot[0]; // 67
	while (ps->a.size > pivot[0])
	{
		if (ps->a.node[REAR]->idx > pivot[1] + base) // L 68 ~ 100 (33개)
			ra(ps);
		else if (ps->a.node[REAR]->idx <= pivot[1] + base) // M  34 ~ 67 (33개)
		{
			pb(ps);
			if (ps->b.node[REAR]->idx <= pivot[0] + base) // S   1 ~ 33 (33개)
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
