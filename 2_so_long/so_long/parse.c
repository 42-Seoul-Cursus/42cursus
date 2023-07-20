/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/20 15:20:34 by anseungwon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (tmp[y][x] == '1')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/wall.xpm",
						&width, &height);
			else if (tmp[y][x] == '0')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/tile.xpm",
						&width, &height);
			else if (tmp[y][x] == 'P')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/char.xpm",
						&width, &height);
			else if (tmp[y][x] == 'E')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/center.xpm",
						&width, &height);
			else if (tmp[y][x] == 'C')
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./xpm/ball.xpm",
						&width, &height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y
					* 64);
			++x;
		}
		++y;
	}
}

void	is_valid_arg(char *av)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = av;
	while (tmp[i] != '\0')
		++i;
	if (tmp[i - 1] != 'r' || tmp[i - 2] != 'e' || tmp[i - 3] != 'b' || tmp[i - 4]
			!= '.' || i < 5)
	{
		perror("Error\nInvalid argument");
		exit(1);
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

void	is_valid_map(t_vars *vars)
{
	is_rectangular(vars);
	is_valid_char(vars);
	is_map_around_one(vars);
	is_dup_char(vars);
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
		perror("Error\n");
		printf("x: %d, y: %d\n", vars->x, vars->y);
		printf("is_dup_char: %llu\n", vars->cnt);
		exit(1);
	}
}

void	is_rectangular(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->map[i] != NULL)
	{
		if (vars->x != (int)ft_strlen(vars->map[i]))
		{
			perror("Error\n");
			printf("x: %d, y: %d\n", vars->x, vars->y);
			printf("is_rectangular: %d\n", i);
			exit(1);
		}
		++i;
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
				perror("Error\n");
				printf("x: %d, y: %d\n", x, y);
				printf("is_valid_char: %c\n", vars->map[y][x]);
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
					perror("Error\n");
					printf("x: %d, y: %d\n", x, y);
					printf("is_map_around_one: %c\n", tmp[y][x]);
					exit(1);
				}
			}
			++x;
		}
		++y;
	}
}

void	set_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->x * 64, vars->y * 64,
			"so_long");
	vars->img = mlx_new_image(vars->mlx, vars->x * 64, vars->y * 64);
	vars->cnt = 0;
}
