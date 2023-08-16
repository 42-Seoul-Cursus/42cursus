/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 05:14:01 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	sort(&ps);
	return (0);
}

void	sort(t_push_swap *ps)
{
	if (ps->a.size == 2 && ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
	else if (ps->a.size == 3)
		sort_3(ps);
	else if (ps->a.size <= 5)
		sort_5(ps);
	else
	{
		partitioning(ps);
		greedy(ps);
	}
}

void	sort_5(t_push_swap *ps)
{
	while (ps->a.size > 3)
	{
		if (ps->a.node[REAR]->idx == ps->sum)
			ra(ps);
		else
			pb(ps);
	}
	sort_3(ps);
	greedy(ps);
}

void	pull_node(t_push_swap *ps)
{
	t_deque_node	*tmp;
	t_cnt			cnt;

	init_cnt(&cnt);
	tmp = ps->a.node[FRONT];
	while (tmp->idx != ps->sum)
	{
		++cnt.rra;
		tmp = tmp->next;
	}
	tmp = ps->a.node[REAR];
	while (tmp->idx != ps->sum)
	{
		++cnt.ra;
		tmp = tmp->prev;
	}
	if (cnt.ra > cnt.rra)
		while (ps->a.node[FRONT]->idx != ps->sum)
			ra(ps);
	else
		while (ps->a.node[FRONT]->idx != ps->sum)
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
		dup = dup_ps(ps);
		ra_rb(&dup, &cnt);
		ra_rrb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		rra_rb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		rra_rrb(&dup, &tmp);
		if (cnt.sum > tmp.sum)
			cnt = tmp;
		deque_rot(ps, cnt);
	}
	pull_node(ps);
}
