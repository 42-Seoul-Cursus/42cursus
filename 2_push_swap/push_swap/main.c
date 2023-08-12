/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/12 21:32:54 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	partitioning(&ps, 0);
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
	if (ps->a.size >= 3 && base <= ps->sum)
		partitioning(ps, pivot[1] + base);
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

void	find_less_cost(t_push_swap *ps, int a_cost, int b_cost)
{
	t_deque_node	*a_tmp;
	t_deque_node	*b_tmp;

	a_tmp = ps->a.node[REAR];
	b_tmp = ps->b.node[REAR];
}

void	greedy(t_push_swap *ps)
{
	int	a_cost;
	int	b_cost;

	while (ps->b.size > 0)
	{
		a_cost = 0;
		b_cost = 0;

	}
}
// 4. b가 비어있으면 가장 큰 값이 a의 바닥에 있는 지 확인
	// 4-1. 가장 큰 값이 a의 바닥에 있으면 종료, 아니면 ra와 rra 비용 비교 이후 종료
