/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 23:21:28 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	leak(void)
// {
// 	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
// 	atexit(leak);
// }

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	// test(&ps);
	partitioning(&ps);
	greedy_l(&ps);
	greedy_m(&ps);
	greedy_s(&ps);
	return (0);
}

void	greedy_l(t_push_swap *ps)
{
	int	bottom;
	int	cnt;

	bottom = ps->sum;
	cnt = 0;
	while (ps->b.size > ps->pivot[1])
	{
		if (ps->b.node[REAR]->idx == bottom)
		{
			--bottom;
			pa(ps);
			while (cnt > 0)
			{
				--cnt;
				rrb(ps);
				if (ps->b.node[REAR]->idx == bottom)
				{
					--bottom;
					pa(ps);
				}
			}
		}
		else
		{
			rb(ps);
			++cnt;
		}
	}
}

void	greedy_m(t_push_swap *ps)
{
	int	bottom;
	int	cnt;

	bottom = ps->pivot[1];
	cnt = 0;
	while (ps->b.size > ps->pivot[0])
	{
		if (ps->b.node[REAR]->idx == bottom)
		{
			--bottom;
			pa(ps);
			while (cnt > 0)
			{
				--cnt;
				rrb(ps);
				if (ps->b.node[REAR]->idx == bottom)
				{
					--bottom;
					pa(ps);
				}
			}
		}
		else
		{
			rb(ps);
			++cnt;
		}
	}
}

void	greedy_s(t_push_swap *ps)
{
	int	bottom;
	int	cnt;

	bottom = ps->pivot[0];
	cnt = 0;
	while (ps->b.size > 0)
	{
		if (ps->b.node[REAR]->idx == bottom)
		{
			--bottom;
			pa(ps);
			while (cnt > 0)
			{
				--cnt;
				rrb(ps);
				if (ps->b.node[REAR]->idx == bottom)
				{
					--bottom;
					pa(ps);
				}
			}
		}
		else
		{
			rb(ps);
			++cnt;
		}
	}
}

// https://80000coding.oopy.io/71fa0b62-6461-463d-b1e1-5eaa2b3a3ca9
// 그리디 알고리즘으로 풀기
