/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 14:29:35 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	test(&ps);
	// quick_sort(&ps);

	return (0);
}

void	quick_sort(t_push_swap *ps)
{
	unsigned int pivot_s;
	unsigned int pivot_m;

	pivot_m = ps->a.size / 3;
	pivot_s = ps->a.size / 3 * 2;
	while (ps->a.size > pivot_m)
	{
		if (ps->a.node[FRONT]->idx < pivot_s)
			pb(ps);
		else
			ra(ps);
	}
	while (ps->a.size > pivot_s)
	{
		if (ps->a.node[FRONT]->idx < pivot_s)
		{
			pb(ps);
			rb(ps);
		}
		else
			ra(ps);
	}
}

/* void quickSort(int arr[], int left, int right)
{
		int	pl = left;
		int pr = right;
		int	pivot = arr[(pl + pr) / 2];	// pivot 설정 (가운데)

		do {
			while (arr[pl] < pivot)	// left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지
				pl++;
			while (arr[pr] > pivot)	// right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지
				pr--;
			if (pl <= pr)	// left가 right보다 왼쪽에 있다면 교환
			{
				swap(int, arr[pl], arr[pr]); // 교환
				pl++;
				pr--;
			}
			printf("%d\n", ++cnt);
		} while (pl <= pr);	// left가 right 보다 오른쪽에 있을 때까지 반복
	// recursion
	if (left < pr)
		quickSort(arr, left, pr);	// 왼쪽 배열 재귀적으로 반복
	if (right > pl)
		quickSort(arr, pl, right);	// 오른쪽 배열 재귀적으로 반복
} */
