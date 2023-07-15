#ifndef SO_LONG_H
# define SO_LONG_H
# include "MiniLibX/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_vars;

// src.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_square(t_data img);
void		draw_circle(t_data img);
void		draw_hexagon(t_data img);

// color.c
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

// hook.c
int			key_hook(int keycode, t_vars *vars);
int			mouse_click_hook(int keycode, int x, int y, t_vars *vars);
int			key_press(int keycode, t_vars *vars);

#endif
