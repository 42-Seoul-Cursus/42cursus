/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 17:17:12 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	init_ps(&ps);
	parse_arg(&ps, ac, av);
	set_idx(&ps);
	sort(&ps);
	return (0);
}
