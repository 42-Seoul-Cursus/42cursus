#include "miniRT.h"

// esc key press event
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

// close button press event
int	exit_hook(void)
{
	exit(0);
}
