/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:14 by seunan            #+#    #+#             */
/*   Updated: 2023/07/21 01:06:03 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	is_valid_arg(ac, av[1]);
	vars.fd = protected_open(av[1]);
	parse_map(&vars);
	set_vars(&vars);
	mlx_hook(vars.win, 3, 1L << 1, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	is_valid_arg(int ac, char *av)
{
	int		i;
	int		slash;
	char	*tmp;

	if (ac != 2)
		exit_with_msg("Error\nEnter 2 arguments");
	i = 0;
	slash = 0;
	tmp = av;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '/')
			slash = i + 1;
		++i;
	}
	if (tmp[i - 1] != 'r' || tmp[i - 2] != 'e' || tmp[i - 3] != 'b'
		|| tmp[i - 4] != '.' || i - slash < 5)
		exit_with_msg("Error\nInvalid argument");
}
