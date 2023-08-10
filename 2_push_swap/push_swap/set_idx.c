/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:32:57 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 23:49:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_deque(int *arr, t_push_swap *ps)
{
	unsigned int	i;
	t_deque_node	*tmp;

	tmp = ps->a.node[FRONT];
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value == arr[i])
		{
			tmp->idx = i;
			i = 0;
			tmp = tmp->next;
		}
		else
			++i;
	}
}

void	sort_arr(int *arr, t_push_swap *ps)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < ps->sum)
	{
		j = i + 1;
		while (j < ps->sum)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void	set_idx(t_push_swap *ps)
{
	int				*arr;
	t_deque_node	*tmp;
	unsigned int	i;

	arr = ft_calloc(ps->sum, sizeof(int));
	tmp = ps->a.node[FRONT];
	i = 0;
	while (tmp != NULL)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
	sort_arr(arr, ps);
	arr_to_deque(arr, ps);
	free(arr);

	// test
	tmp = ps->a.node[FRONT];
	while (tmp != NULL)
	{
		printf("value: %d, idx: %d\n", tmp->value, tmp->idx);
		tmp = tmp->next;
	}
}
