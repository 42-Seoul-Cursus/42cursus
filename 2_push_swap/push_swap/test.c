/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:41:36 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 19:36:58 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_deque(t_push_swap *ps)

{
	t_deque			*a = &(ps->a);
	t_deque			*b = &(ps->b);
	t_deque_node	*a_tmp = a->node[REAR];
	t_deque_node	*b_tmp = b->node[REAR];
	unsigned int	i;

	i = 0;
	while (i < a->size || i < b->size)
	{
		if (i < a->size && a_tmp != NULL)
			printf("\x1b[31m%d\t", a_tmp->value);
		else
			printf("\t");
		if (i < b->size && b_tmp != NULL)
			printf("\x1b[32m%d\n", b_tmp->value);
		else
			printf("\n");
		if (a_tmp == NULL || a_tmp->prev == NULL)
			;
		else
			a_tmp = a_tmp->prev;
		if (b_tmp == NULL || b_tmp->prev == NULL)
			;
		else
			b_tmp = b_tmp->prev;
		++i;
	}
	printf("\x1b[30ma\tb\n");
}
