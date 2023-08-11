/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:40:51 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 18:28:57 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg(t_push_swap *ps, int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		enque(&ps->a, FRONT, new_node(ft_atoi(av[i])));
		++i;
		++ps->sum;
	}
	set_idx(ps);
}

t_deque_node	*new_node(int value)
{
	t_deque_node	*node;

	node = (t_deque_node *)calloc(1, sizeof(t_deque_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	set_idx(t_push_swap *ps)
{
	int				*arr;
	t_deque_node	*tmp;
	int				i;

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
	set_idx_in_deque(arr, ps);
	free(arr);
}

void	set_idx_in_deque(int *arr, t_push_swap *ps)
{
	int				i;
	t_deque_node	*tmp;

	tmp = ps->a.node[FRONT];
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value == arr[i])
		{
			tmp->idx = i + 1;
			i = 0;
			tmp = tmp->next;
		}
		else
			++i;
	}
}

void	sort_arr(int *arr, t_push_swap *ps)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ps->sum)
	{
		j = i + 1;
		while (j < ps->sum)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
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
