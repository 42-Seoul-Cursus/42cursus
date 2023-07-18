// gcc hook.c -L./MiniLibX -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		exit(0);
	if (keycode == 13 | keycode == 126)
		printf("W\n");
	if (keycode == 0 | keycode == 123)
		printf("A\n");
	if (keycode == 1 | keycode == 125)
		printf("S\n");
	if (keycode == 2 | keycode == 124)
		printf("D\n");
	return (0);
}

int	exit_window(t_vars *vars)
{
	(void)vars;
	exit(0);
}
