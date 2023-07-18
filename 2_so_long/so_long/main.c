#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;
	t_list	**map = ft_calloc(1, sizeof(t_list *));
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	parse_map(map, &vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);

	int a = 64;
	int b = 64;
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/ball.xpm", &a, &b);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/center.xpm", &a, &b);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 64);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/char.xpm", &a, &b);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 128);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/tile.xpm", &a, &b);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 64, 0);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./xpm/wall.xpm", &a, &b);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 64, 64);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_click_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
