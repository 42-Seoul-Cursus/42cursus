#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data img)
{
	for (int i = 100; i <= 200; i++)
		my_mlx_pixel_put(&img, i, 100, 0x00FF0000);
	for (int i = 100; i <= 200; i++)
		my_mlx_pixel_put(&img, 100, i, 0x00FF0000);
	for (int i = 100; i <= 200; i++)
		my_mlx_pixel_put(&img, i, 200, 0x00FF0000);
	for (int i = 100; i <= 200; i++)
		my_mlx_pixel_put(&img, 200, i, 0x00FF0000);
}

void	draw_circle(t_data img)
{
	int x = 0;
	int y = 50;
	int decision = 3 - 2 * 50;

	while (y >= x)
	{
		my_mlx_pixel_put(&img, 400 + x, 150 + y, 0x000000FF);
		my_mlx_pixel_put(&img, 400 - x, 150 + y, 0x000000FF);
		my_mlx_pixel_put(&img, 400 + x, 150 - y, 0x000000FF);
		my_mlx_pixel_put(&img, 400 - x, 150 - y, 0x000000FF);
		my_mlx_pixel_put(&img, 400 + y, 150 + x, 0x000000FF);
		my_mlx_pixel_put(&img, 400 - y, 150 + x, 0x000000FF);
		my_mlx_pixel_put(&img, 400 + y, 150 - x, 0x000000FF);
		my_mlx_pixel_put(&img, 400 - y, 150 - x, 0x000000FF);

		if (decision <= 0)
		{
			decision += 4 * x + 6;
		}
		else
		{
			decision += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

void	draw_hexagon(t_data img)
{
	const int num_sides = 6;
	const double angle = 2 * M_PI / num_sides;

	int x, y;
	for (int i = 0; i < num_sides; i++)
	{
		x = 500 + 50 * cos(i * angle);
		y = 100 + 50 * sin(i * angle);

		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
	}

	// Connect the last and first points to complete the hexagon
	int last_x = 500 + 50 * cos((num_sides - 1) * angle);
	int last_y = 100 + 50 * sin((num_sides - 1) * angle);

	my_mlx_pixel_put(&img, last_x, last_y, 0x0000FF00);
}
