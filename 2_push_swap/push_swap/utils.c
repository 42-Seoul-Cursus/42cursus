/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:10:49 by seunan            #+#    #+#             */
/*   Updated: 2023/07/27 17:28:27 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enque(struct s_stack *st, enum e_rear rear, struct s_stack_node *node)
{
	if (st->size == 0)
	{
		st->node[rear] = node;
		st->node[rear]->next = NULL;
		st->node[rear]->prev = NULL;
	}
	else
	{
		st->node[rear]->prev = node;
		node->next = st->node[rear];
		st->node[rear] = node;
	}
	st->size++;
}

struct s_stack	*deque(struct s_stack *st, enum e_rear rear)
{
	struct s_stack_node	*tmp;

	if (st->size == 0)
		return (NULL);
	tmp = st->node[rear];
	if (st->size == 1)
	{
		st->node[rear] = NULL;
		st->node[rear]->next = NULL;
		st->node[rear]->prev = NULL;
	}
	else
	{
		st->node[rear] = st->node[rear]->next;
		st->node[rear]->prev = NULL;
		tmp->next = NULL;
	}
	st->size--;
	return (tmp);
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
