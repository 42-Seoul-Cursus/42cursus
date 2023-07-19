/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:14 by seunan            #+#    #+#             */
/*   Updated: 2023/07/19 17:25:13 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	leak(void)
{
	system("leaks so_long > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}

int	main(int ac, char *av[])
{
	atexit(leak);
	t_vars	vars;

	if (ac != 2)
		return (1);
	vars.fd = open(av[1], O_RDONLY);
	parse_map(&vars);
	set_vars(&vars);
	print_map(&vars, 64, 64);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
