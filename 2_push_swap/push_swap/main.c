/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/16 23:41:26 by seunan           ###   ########.fr       */
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
	return (0);
}

void	pull_node(t_push_swap *ps)
{
	t_deque_node	*tmp;
	t_cnt			cnt;

	init_cnt(&cnt);
	tmp = ps->a.node[FRONT];
	cnt.rra = 1;
	while (tmp->idx != 0)
	{
		++cnt.rra;
		tmp = tmp->next;
	}
	tmp = ps->a.node[REAR];
	while (tmp->idx != 0)
	{
		++cnt.ra;
		tmp = tmp->prev;
	}
	if (cnt.ra > cnt.rra)
		while (ps->a.node[FRONT]->idx != 0)
			ra(ps);
	else
		while (ps->a.node[FRONT]->idx != 0)
			rra(ps);
}

void	deque_rot(t_push_swap *ps, t_cnt cnt)
{
	while (cnt.ra > 0 && cnt.rb > 0)
	{
		rr(ps);
		--cnt.ra;
		--cnt.rb;
	}
	while (cnt.rra > 0 && cnt.rrb > 0)
	{
		rrr(ps);
		--cnt.rra;
		--cnt.rrb;
	}
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
	t_push_swap	dup;
	t_cnt		cnt;
	t_cnt		tmp;

	while (ps->b.size > 0)
	{
		dup = dup_ps(&ps);
		ra_rb(&dup, &cnt);
		dup = dup_ps(&ps);
		ra_rrb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		dup = dup_ps(&ps);
		rra_rb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		dup = dup_ps(&ps);
		rra_rrb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		deque_rot(ps, cnt);
	}
	pull_node(ps);
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
		greedy(ps);
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
