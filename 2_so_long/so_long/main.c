#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
		return (1);
	vars.fd = open(av[1], O_RDONLY);
	parse_map(&vars);
	set_vars(&vars);
	print_map_first(&vars, 64, 64);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
