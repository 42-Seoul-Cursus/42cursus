// gcc hook.c -L./MiniLibX -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
