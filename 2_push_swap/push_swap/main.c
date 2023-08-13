/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/13 20:56:49 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	if (ps.a.size == 2 && ps.a.node[REAR]->idx > ps.a.node[REAR]->prev->idx)
		sa(&ps);
	else if (ps.a.size == 3)
		sort_3(&ps);
	else if (ps.a.size > 3)
	{
		partitioning(&ps, 0);
		sort_l(&ps);
	}
	return (0);
}
// 1. 구간 나누고 b로 옮기기
void	partitioning(t_push_swap *ps, int base)
{
	int	pivot[2];

	pivot[0] = ps->a.size / 3;        // 33
	pivot[1] = ps->a.size - pivot[0]; // 67
	while (ps->a.size > pivot[0])
	{
		if (ps->a.node[REAR]->idx > pivot[1] + base) // L 68 ~ 100 (33개)
			ra(ps);
		else if (ps->a.node[REAR]->idx <= pivot[1] + base) // M  34 ~ 67 (33개)
		{
			pb(ps);
			if (ps->b.node[REAR]->idx <= pivot[0] + base) // S   1 ~ 33 (33개)
				rb(ps);
		}
	}
	if (ps->a.size > 3 && base <= ps->sum)
		partitioning(ps, pivot[1] + base);
	if (ps->a.size == 3)
		sort_3(ps);
	if (ps->a.size == 2 && ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
		sa(ps);
}

void	sort_l(t_push_swap *ps)
{
	int				target;
	int				future;
	int				flag;
	int				f;
	int				cnt_rb;
	int				cnt_rrb;
	t_deque_node	*tmp;

	target = ps->a.node[REAR]->idx - 1;
	while (target > ps->sum - ps->sum / 3)
	{
		future = target - 1;
		flag = 0;
		cnt_rb = 0;
		cnt_rrb = 1;
		tmp = ps->b.node[REAR];
		while (tmp->idx != target)
		{
			tmp = tmp->prev;
			cnt_rb++;
		}
		tmp = ps->b.node[FRONT];
		while (tmp->idx != target)
		{
			tmp = tmp->next;
			cnt_rrb++;
		}
		if (cnt_rb + 1 > cnt_rrb)
		{
			while (cnt_rrb > 0)
			{
				if (ps->b.node[REAR]->idx == future && flag < 2)
				{
					--future;
					++flag;
					pa(ps);
					ra(ps);
				}
				rrb(ps);
				cnt_rrb--;
			}
		}
		else
		{
			while (cnt_rb > 0)
			{
				f = 0;
				if (ps->b.node[REAR]->idx == future && flag < 2)
				{
					--future;
					++flag;
					++f;
					pa(ps);
					ra(ps);
				}
				if (f == 0)
					rb(ps);
				cnt_rb--;
			}
		}
		pa(ps);
		target -= flag + 1;
		if (flag == 1)
			rra(ps);
		else if (flag == 2)
		{
			rra(ps);
			rra(ps);
			if (ps->a.node[REAR]->idx > ps->a.node[REAR]->prev->idx)
				sa(ps);
		}
	}
}

// 2. b에서 a로 옮기기
	// 2-1. a는 무조건 정렬된 상태여야 함 (rra, ra를 통해 정렬된 상태도 가능)
	// 2-2. b에서 a에 들어갈 수 있는 노드 움직이는 비용 + a에서 해당 노드에 맞는 위치로 이동하는 비용
		// 2-2-1. 노드 움직이는 비용(rrb, rb) + a에서 해당 노드에 맞는 위치로 이동하는 비용(rra, ra) 이 때 rr, rrr 가능
		// 2-2-2. pa로 a에 옮김
	// 500 ~ 2 사이 1 들어갈 수 있음
	// 1. b rear 노드가 a의 노드 사이에 들어갈 때 드는 비용 확인 (ra or rra + pa)
	// 2. b 노드들을 모두 순회(b rear노드의 횟수보다 작게)하며 가장 작은 비용 찾기
// 3. 2 반복

// int	find_less_rotate(t_deque *a, int idx)
// {
// 	t_deque_node	*top;
// 	t_deque_node	*bot;
// 	int				ra_cnt;
// 	int				rra_cnt;

// 	top = a->node[REAR];
// 	bot = a->node[FRONT];
// 	if (top->idx > idx && bot->idx < idx)
// 		return (0);
// 	ra_cnt = 0;
// 	while (top != NULL)
// 	{
// 		if (top->idx > idx && top->prev->idx < idx)
// 			break;
// 		top = top->prev;
// 		++ra_cnt;
// 	}
// 	rra_cnt = 0;
// 	while (bot != NULL)
// 	{
// 		if (bot->idx > idx && bot->next->idx < idx)
// 			break;
// 		bot = bot->next;
// 		++rra_cnt;
// 	}
// }

// void	find_less_cost(t_push_swap *ps, int a_cost, int b_cost)
// {

// }

// void	sort_l(t_push_swap *ps)
// {
// 	int	a_cost;
// 	int	b_cost;

// 	while (ps->b.size > 0)
// 	{
// 		a_cost = 0;
// 		b_cost = 0;

// 	}
// }
// 4. b가 비어있으면 가장 큰 값이 a의 바닥에 있는 지 확인
	// 4-1. 가장 큰 값이 a의 바닥에 있으면 종료, 아니면 ra와 rra 비용 비교 이후 종료
