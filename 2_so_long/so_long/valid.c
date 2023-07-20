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

void	is_escape(t_vars *vars)
{
	char	**visited;
	int		backup[3];

	backup[0] = vars->p[0];
	backup[1] = vars->p[1];
	backup[2] = vars->ball;
	visited = dup_map(vars);
	vars->is_escape = 0;
	dfs_find_c(vars, vars->p[0], vars->p[1], visited);
	if (vars->is_escape == 0)
	{
		perror("Error\nUnable to escape");
		exit(1);
	}
	vars->is_escape = 0;
	dfs_find_e(vars, vars->p[0], vars->p[1], visited);
	if (vars->is_escape == 0)
	{
		perror("Error\nUnable to escape");
		exit(1);
	}
	free_map(visited);
	vars->p[0] = backup[0];
	vars->p[1] = backup[1];
	vars->ball = backup[2];
}

void	is_valid_arg(int ac, char *av)
{
	int		i;
	int		slash;
	char	*tmp;

	if (ac != 2)
	{
		perror("Error\nEnter 2 arguments");
		exit(1);
	}
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
	{
		perror("Error\nInvalid argument");
		exit(1);
	}
}

void	is_dup_char(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->cnt = 0;
	vars->ball = 0;
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
	{
		perror("Error\nMore than 1 character on the map");
		exit(1);
	}
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
			{
				perror("Error\nContains unrecognized characters");
				exit(1);
			}
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
			{
				if (tmp[y][x] != '1')
				{
					perror("Error\nMap is not surrounded by \'1\'");
					exit(1);
				}
			}
			++x;
		}
		++y;
	}
}
