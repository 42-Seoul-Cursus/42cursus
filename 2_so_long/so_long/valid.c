/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:16:14 by seunan            #+#    #+#             */
/*   Updated: 2023/07/20 17:09:07 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_vars *vars)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (vars->y + 1));
	while (i < vars->y)
	{
		tmp[i] = ft_strdup(vars->map[i]);
		++i;
	}
	return (tmp);
}

void	is_escape(t_vars *vars)
{
	char	**visited;

	visited = dup_map(vars);
	vars->is_exit = 0;
	dfs(vars, vars->player[0], vars->player[1], visited);
	if (vars->is_exit == 0)
	{
		perror("Error\nUnable to escape :");
		exit(1);
	}
}

void	dfs(t_vars *vars, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= vars->x || y >= vars->y)
		return ;
	if (visited[y][x] == 'C')
	{
		visited[y][x] = '0';
		--vars->cnt;
		return ;
	}
	if (visited[y][x] == '1')
		return ;
	if (vars->map[y][x] == 'E')
	{
		if (vars->ball == 0)
			vars->is_exit = 1;
		else
			return ;
	}
	visited[y][x] = '1';
	dfs(vars, x + 1, y, visited);
	dfs(vars, x - 1, y, visited);
	dfs(vars, x, y + 1, visited);
	dfs(vars, x, y - 1, visited);
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
	if (tmp[i - 1] != 'r' || tmp[i - 2] != 'e' || tmp[i - 3] != 'b' || tmp[i - 4]
			!= '.' || i - slash < 5)
	{
		perror("Error\nInvalid argument");
		exit(1);
	}
}

void	is_valid_map(t_vars *vars)
{
	is_rectangular(vars);
	is_valid_char(vars);
	is_map_around_one(vars);
	is_dup_char(vars);
	is_escape(vars);
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
				vars->player[0] = x;
				vars->player[1] = y;
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
