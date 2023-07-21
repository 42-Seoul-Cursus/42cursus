/* ************************************************************************** */
/*                                                                            */
/*                                                       ::     :::::::   */
/*   valid.c                                           +:     +:   +:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:16:14 by seunan            #+#    #+#             */
/*   Updated: 2023/07/20 18:33:18 by anseungwon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(t_vars *vars)
{
	vars->cnt = 0;
	vars->ball = 0;
	is_rectangular(vars);
	is_valid_char(vars);
	is_map_around_one(vars);
	is_dup_char(vars);
	is_escape(vars);
}

void	is_rectangular(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->map[i] != NULL)
	{
		if (vars->x != (int)ft_strlen(vars->map[i]))
			exit_with_msg("Error\nis not rectangular");
		++i;
	}
}

void	is_dup_char(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'P')
			{
				vars->p[0] = x;
				vars->p[1] = y;
				++(vars->cnt);
			}
			else if (vars->map[y][x] == 'E')
				++(vars->cnt);
			if (vars->map[y][x] == 'C')
				++(vars->ball);
			++x;
		}
		++y;
	}
	if (vars->cnt != 2)
		exit_with_msg("Error\nMore than 1 character on the map");
}

void	is_valid_char(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E'
				&& vars->map[y][x] != 'P')
				exit_with_msg("Error\nContains unrecognized characters");
			++x;
		}
		++y;
	}
}

void	is_map_around_one(t_vars *vars)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = vars->map;
	while (tmp[y] != NULL)
	{
		x = 0;
		while (tmp[y][x] != '\0')
		{
			if (x == 0 || y == 0 || x == vars->x - 1 || y == vars->y - 1)
				if (tmp[y][x] != '1')
					exit_with_msg("Error\nMap is not surrounded by \'1\'");
			++x;
		}
		++y;
	}
}
