/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/18 01:28:34 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leak(void)
{
	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}

int	main(int ac, char *av[])
{
	atexit(leak);
	t_push_swap	ps;

	if (ac < 2)
		exit(EXIT_FAILURE);
	init_ps(&ps);
	parse_arg(&ps, ac, av);
	set_idx(&ps);
	if (is_sorted(&ps))
		exit(EXIT_SUCCESS);
	sort(&ps);
	free_q(&ps);
	return (0);
}
