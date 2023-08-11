/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 22:51:08 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	// test(&ps);
	partitioning(&ps);
	return (0);
}

void	partitioning(t_push_swap *ps)
{
	int	pivot[2];

	if (ps->a.size <= 3)
	{
		if (ps->a.size == 3)
			sort_3(ps);
		else if (ps->a.size == 2 && ps->a.node[FRONT]->idx < ps->a.node[REAR]->idx)
			sa(ps);
		exit(EXIT_SUCCESS);
	}
	pivot[0] = ps->a.size / 3;  // 3
	pivot[1] = ps->a.size - pivot[0]; // 6
	while (ps->a.size > pivot[0])
	{
		if (ps->a.node[REAR]->idx > pivot[1])       // L 7 ~ 9
			ra(ps);
		else if (ps->a.node[REAR]->idx <= pivot[1]) // M 4 ~ 6
		{
			pb(ps);
			if (ps->b.node[REAR]->idx <= pivot[0])  // S 1 ~ 3
				rb(ps);
		}
	}
	while (ps->a.size)
		pb(ps);
}

// https://80000coding.oopy.io/71fa0b62-6461-463d-b1e1-5eaa2b3a3ca9
// 그리디 알고리즘으로 풀기
