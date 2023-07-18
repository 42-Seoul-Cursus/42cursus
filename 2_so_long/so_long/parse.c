#include "so_long.h"

void	print_map(t_list **map, t_vars *vars)
{
	char	*buf;
	int		i;

	while (*map != NULL)
	{
		buf = (*map)->content;
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '1')
				vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./xpm/wall.xpm", &(*vars).width, &(*vars).height);
			else if (buf[i] == '0')
				vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./xpm/tile.xpm", &(*vars).width, &(*vars).height);
			else if (buf[i] == 'P')
				vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./xpm/char.xpm", &(*vars).width, &(*vars).height);
			else if (buf[i] == 'E')
				vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./xpm/center.xpm", &(*vars).width, &(*vars).height);
			else if (buf[i] == 'C')
				vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./xpm/ball.xpm", &(*vars).width, &(*vars).height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, i * 64, (*map)->index * 64);
			printf("%c", buf[i]);
			++i;
		}
		printf("\n");
		*map = (*map)->next;
	}
}

void	parse_map(t_list **map, t_vars *vars)
{
	int		i;
	char	*buf;

	i = 0;
	while (1)
	{
		buf = get_next_line(vars->fd);
		if (buf == NULL)
			break;
		ft_lstadd_back(map, ft_lstnew(buf, i++));
	}
	vars->x = ft_strlen((*map)->content);
	vars->y = i;
	// while (*map != NULL)
	// {
	// 	printf("%d %s\n",(*map)->index, (*map)->content);
	// 	(*map) = (*map)->next;
	// }
}

void	set_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->x * 64, vars->y * 64, "so_long");
	printf("%d %d\n", vars->x, vars->y);
	vars->img.img = mlx_new_image(vars->mlx, vars->x * 64, vars->y * 64);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bits_per_pixel),
			&(vars->img.line_length), &(vars->img.endian));

	vars->width = 64;
	vars->height = 64;
}
