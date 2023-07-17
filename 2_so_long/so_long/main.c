#include "so_long.h"

int	render_next_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);

	draw_square(vars.img);
	draw_circle(vars.img);
	draw_hexagon(vars.img);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);

	mlx_xpm_file_to_image()
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_mouse_hook(vars.win, mouse_click_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
