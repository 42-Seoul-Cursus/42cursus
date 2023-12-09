#ifndef MINIRT_H
# define MINIRT_H

# include "MiniLibX/mlx.h"
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vec
{
	double x;
	double y;
	double z;
}	t_vec;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/* vec_operations1.c */
t_vec	vec_add(t_vec *v1, t_vec *v2);
t_vec	vec_sub(t_vec *v1, t_vec *v2);
t_vec	vec_mul(t_vec *v1, double t);
t_vec	vec_div(t_vec *v1, double t);
double	vec_length(t_vec v);
double	sqrt(double n);

/* vec_operations2.c */
t_vec	vec(double x, double y, double z);
double	vec_dot(t_vec *v1, t_vec *v2);
t_vec	vec_cross(t_vec *v1, t_vec *v2);
t_vec	vec_unit(t_vec v);

/* color.c */
int		get_color(int t, t_color pixel_color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
