#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;
	t_list	**map = ft_calloc(1, sizeof(t_list *));

	if (ac != 2)
		return (1);
	vars.fd = open(av[1], O_RDONLY);
	parse_map(map, &vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x * 64, vars.y * 64, "so_long");
	printf("%d %d\n", vars.x, vars.y);
	vars.img.img = mlx_new_image(vars.mlx, vars.x * 64, vars.y * 64);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);

	vars.width = 64;
	vars.height = 64;

	char	*buf;
	int		i;

	while (*map != NULL)
	{
		buf = (*map)->content;
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '1')
				vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/wall.xpm", &vars.width, &vars.height);
			else if (buf[i] == '0')
				vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/tile.xpm", &vars.width, &vars.height);
			else if (buf[i] == 'P')
				vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/char.xpm", &vars.width, &vars.height);
			else if (buf[i] == 'E')
				vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/center.xpm", &vars.width, &vars.height);
			else if (buf[i] == 'C')
				vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/ball.xpm", &vars.width, &vars.height);
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, i * 64, (*map)->index * 64);
			printf("%c", buf[i]);
			++i;
		}
		printf("\n");
		*map = (*map)->next;
	}

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_window, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
