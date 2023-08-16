/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:10:49 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 03:14:34 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enque(t_deque *q, enum e_rear rear, t_deque_node *node)
{
	if (q->size == 0)
	{
		node->next = NULL;
		node->prev = NULL;
		q->node[FRONT] = node;
		q->node[REAR] = node;
	}
	else if (rear == FRONT)
	{
		q->node[FRONT]->prev = node;
		node->next = q->node[FRONT];
		node->prev = NULL;
	}
	else if (rear == REAR)
	{
		q->node[REAR]->next = node;
		node->prev = q->node[REAR];
		node->next = NULL;
	}
	q->node[rear] = node;
	++(q->size);
}

t_deque_node	*deque(t_deque *q, enum e_rear rear)
{
	t_deque_node	*node;

	if (q->size == 0)
		return (NULL);
	node = q->node[rear];
	if (q->size == 1)
	{
		q->node[0] = NULL;
		q->node[1] = NULL;
	}
	else if (rear == FRONT)
	{
		q->node[FRONT] = node->next;
		q->node[FRONT]->prev = NULL;
	}
	else if (rear == REAR)
	{
		q->node[REAR] = node->prev;
		q->node[REAR]->next = NULL;
	}
	--(q->size);
	return (node);
}

int	push(t_deque *from, t_deque *to)
{
	t_deque_node	*node;

	if (from->size < 1)
		return (0);
	node = deque(from, REAR);
	enque(to, REAR, node);
	return (1);
}

int	swap(t_deque *q)
{
	t_deque_node	*node[2];

	if (q->size < 2)
		return (0);
	node[0] = deque(q, REAR);
	node[1] = deque(q, REAR);
	enque(q, REAR, node[0]);
	enque(q, REAR, node[1]);
	return (1);
}

int	rotate(t_deque *q, enum e_rear rear)
{
	t_deque_node	*node;

	if (q->size < 1)
		return (0);
	node = deque(q, rear);
	enque(q, !rear, node);
	return (1);
}
