/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:10:49 by seunan            #+#    #+#             */
/*   Updated: 2023/07/28 19:25:36 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rear  : 가장 위
// front : 가장 밑
void	enque(struct s_stack *st, enum e_rear rear, struct s_stack_node *node)
{
	if (st->size == 0)
	{
		st->node[0] = node;
		st->node[0]->next = NULL;
		st->node[0]->prev = NULL;
		st->node[1] = node;
		st->node[1]->next = NULL;
		st->node[1]->prev = NULL;
	}
	else if (rear == FRONT)
	{
		st->node[rear]->prev = node;
		node->next = st->node[rear];
		node->prev = NULL;
	}
	else if (rear == REAR)
	{
		st->node[rear]->next = node;
		node->prev = st->node[rear];
		node->next = NULL;
	}
	st->node[rear] = node;
	++st->size;
}

t_stack	*deque(struct s_stack *st, enum e_rear rear)
{
	struct s_stack_node	*node;

	if (st->size == 0)
		return (NULL);
	node = st->node[rear];
	if (st->size == 1)
	{
		st->node[0] = NULL;
		st->node[1] = NULL;
	}
	else if (rear == FRONT)
	{
		st->node[rear] = node->next;
		st->node[rear]->prev = NULL;
	}
	else if (rear == REAR)
	{
		st->node[rear] = node->prev;
		st->node[rear]->next = NULL;
	}
	--st->size;
	return (node);
}

int	push(struct s_stack *from, struct s_stack *to)
{
	struct s_stack_node	*node;

	if (from->size < 1)
		return (0); // 뺄 게 없으므로 명령어 처리 X
	node = deque(from, FRONT);
	enque(to, FRONT, node);
	return (1);
}

int	swap(t_stack *st)
{
	struct s_stack_node	*node[2];

	if (st->size < 2)
		return (0); // swap 할 게 없으므로 명령어 처리 X
	node[0] = deque(st, FRONT);
	node[1] = deque(st, FRONT);
	enque(st, FRONT, node[0]);
	enque(st, FRONT, node[1]);
	return (1);
}

int	rotate(t_stack *st, enum e_rear rear)
{
	struct s_stack_node	*node;

	if (st->size < 1)
		return (0); // 뺄 게 없으므로 명령어 처리 X
	node = deque(st, rear);
	enque(st, !rear, node);
	return (1);
}
