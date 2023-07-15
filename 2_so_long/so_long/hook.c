// gcc hook.c -L./MiniLibX -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"
#include <stdio.h>

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	(void) vars;
	return (0);
}

int	mouse_click_hook(int keycode, int x, int y, t_vars *vars)
{
	printf("Hello from mouse_click_hook!\n");
	printf("button: %d\n", keycode);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	(void) vars;
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	printf("Hello from key_press!\n");
	printf("keycode: %d\n", keycode);
	(void) vars;
	return (0);
}
