/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:04:56 by anseungwon        #+#    #+#             */
/*   Updated: 2023/07/20 19:05:50 by anseungwon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(t_vars *vars)
{
	is_rectangular(vars);
	is_valid_char(vars);
	is_map_around_one(vars);
	is_dup_char(vars);
	is_escape(vars);
}

void	dfs_find_c(t_vars *vars, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= vars->x || y >= vars->y)
		return ;
	if (visited[y][x] == '1' || visited[y][x] == '2' | visited[y][x] == 'E')
		return ;
	if (visited[y][x] == 'C')
	{
		--vars->ball;
		vars->p[0] = x;
		vars->p[1] = y;
	}
	visited[y][x] = '2';
	if (vars->ball == 0)
	{
		vars->is_escape = 1;
		return ;
	}
	dfs_find_c(vars, x + 1, y, visited);
	dfs_find_c(vars, x - 1, y, visited);
	dfs_find_c(vars, x, y + 1, visited);
	dfs_find_c(vars, x, y - 1, visited);
}

void	dfs_find_e(t_vars *vars, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= vars->x || y >= vars->y)
		return ;
	if (visited[y][x] == '1' || visited[y][x] == '3')
		return ;
	if (visited[y][x] == 'E')
	{
		vars->is_escape = 1;
		return ;
	}
	visited[y][x] = '3';
	dfs_find_e(vars, x + 1, y, visited);
	dfs_find_e(vars, x - 1, y, visited);
	dfs_find_e(vars, x, y + 1, visited);
	dfs_find_e(vars, x, y - 1, visited);
}

void	free_map(char **visited)
{
	int	i;

	i = 0;
	while (visited[i] != NULL)
	{
		free(visited[i]);
		++i;
	}
	free(visited);
}

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
