/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_rot_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 03:09:40 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 03:10:21 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	dup_ps(t_push_swap *ps)
{
	t_push_swap		dup;
	t_deque_node	*tmp;
	t_deque_node	*cur;

	init_ps(&dup);
	cur = ps->a.node[FRONT];
	while (cur != NULL)
	{
		tmp = cur->next;
		enque(&(dup.a), REAR, cur);
		cur = tmp;
	}
	cur = ps->b.node[FRONT];
	while (cur != NULL)
	{
		tmp = cur->next;
		enque(&(dup.b), REAR, cur);
		cur = tmp;
	}
	dup.sum = ps->sum;
	return (dup);
}

void	ra_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
		cnt->ra++;
	rotate(&(ps->a), REAR);
}

void	rb_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
		cnt->rb++;
	rotate(&(ps->b), REAR);
}

void	rra_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
		cnt->rra++;
	rotate(&(ps->a), FRONT);
}

void	rrb_x(t_push_swap *ps, t_cnt *cnt)
{
	if (cnt != NULL)
		cnt->rrb++;
	rotate(&(ps->b), FRONT);
}
