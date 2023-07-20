/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/21 01:06:16 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_file_to_img(t_vars *vars, int width, int height, char tmp)
{
	if (tmp == '1')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/wall.xpm", &width,
				&height);
	else if (tmp == '0')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/tile.xpm", &width,
				&height);
	else if (tmp == 'P')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/char.xpm", &width,
				&height);
	else if (tmp == 'E')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/center.xpm", &width,
				&height);
	else if (tmp == 'C')
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/ball.xpm", &width,
				&height);
}

void	print_map(t_vars *vars, int width, int height)
{
	char	**tmp;
	int		x;
	int		y;

	tmp = vars->map;
	y = 0;
	while (tmp[y] != NULL)
	{
		x = 0;
		while (tmp[y][x] != '\0')
		{
			xpm_file_to_img(vars, width, height, tmp[y][x]);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y
				* 64);
			++x;
		}
		++y;
	}
}

void	parse_map(t_vars *vars)
{
	int		i;
	char	*buf;

	i = 0;
	vars->map = NULL;
	while (1)
	{
		buf = get_next_line(vars->fd);
		if (buf == NULL)
			break ;
		vars->map = protected_realloc(vars->map, sizeof(char *) * (i + 2), i
				+ 1);
		vars->map[i++] = buf;
		vars->map[i] = NULL;
	}
	vars->x = ft_strlen(vars->map[0]);
	vars->y = i;
	is_valid_map(vars);
}

void	set_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->x * 64, vars->y * 64,
			"so_long");
	vars->img = mlx_new_image(vars->mlx, vars->x * 64, vars->y * 64);
	vars->cnt = 0;
	print_map(vars, 64, 64);
}
