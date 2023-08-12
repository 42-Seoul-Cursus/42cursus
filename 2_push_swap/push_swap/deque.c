/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:10:49 by seunan            #+#    #+#             */
/*   Updated: 2023/08/12 21:38:38 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enque(t_deque *q, enum e_rear rear, t_deque_node *node)
{
	if (q->size == 0) // 스택이 비어있는 경우 FRONT와 REAR가 하나의 node를 가리킨다.
	{
		node->next = NULL;
		node->prev = NULL;
		q->node[FRONT] = node;
		q->node[REAR] = node;
	}
	else if (rear == FRONT) // 스택의 FRONT에 node를 넣는다.
	{
		q->node[FRONT]->prev = node; // 기존의 FRONT node의 prev(FRONT 방향)를 새로운 node로 설정
		node->next = q->node[FRONT]; // 새로운 node의 next(REAR 방향)를 기존의 FRONT node로 설정
		node->prev = NULL; // node가 q->node[FRONT]가 되므로 prev는 NULL
	}
	else if (rear == REAR) // 스택의 REAR에 node를 넣는다.
	{
		q->node[REAR]->next = node; // 기존의 REAR node의 next(REAR 방향)를 새로운 node로 설정
		node->prev = q->node[REAR]; // 새로운 node의 prev(FRONT 방향)를 기존의 REAR node로 설정
		node->next = NULL; // node가 q->node[REAR]가 되므로 next는 NULL
	}
	q->node[rear] = node; // 새로운 node를 q->node[rear]로 설정
	++(q->size); // 스택의 size를 1 증가
}

t_deque_node	*deque(t_deque *q, enum e_rear rear)
{
	t_deque_node	*node; // 빼낼 node

	if (q->size == 0)
		return (NULL);
	node = q->node[rear]; // 빼낼 node를 q->node[rear]로 설정
	if (q->size == 1) // 빼낼 node가 스택의 유일한 node인 경우
	{
		q->node[0] = NULL;
		q->node[1] = NULL;
	}
	else if (rear == FRONT) // 스택의 FRONT에서 빼낼 경우
	{
		q->node[FRONT] = node->next;
		q->node[FRONT]->prev = NULL;
	}
	else if (rear == REAR) // 스택의 REAR에서 빼낼 경우
	{
		q->node[REAR] = node->prev;
		q->node[REAR]->next = NULL;
	}
	--(q->size); // 스택의 size를 1 감소
	return (node);
}

// from에서 빼서 to로 넣는다.
int	push(t_deque *from, t_deque *to)
{
	t_deque_node	*node;

	if (from->size < 1)
		return (0); // 뺄 게 없으므로 명령어 처리 X
	node = deque(from, REAR);
	enque(to, REAR, node);
	return (1);
}

// 한 스택 내 두 node의 value를 바꾼다.
int	swap(t_deque *q)
{
	t_deque_node	*node[2];

	if (q->size < 2)
		return (0); // swap 할 게 없으므로 명령어 처리 X
	node[0] = deque(q, REAR);
	node[1] = deque(q, REAR);
	enque(q, REAR, node[0]);
	enque(q, REAR, node[1]);
	return (1);
}

// 스택을 회전시킨다.
int	rotate(t_deque *q, enum e_rear rear)
{
	t_deque_node	*node;

	if (q->size < 1)
		return (0); // 뺄 게 없으므로 명령어 처리 X
	node = deque(q, rear);
	enque(q, !rear, node);
	return (1);
}
