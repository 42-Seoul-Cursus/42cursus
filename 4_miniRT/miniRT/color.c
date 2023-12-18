#include "miniRT.h"

// Transparency, Red, Green, Blue
// 0xTTRRGGBB
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_color(int t, t_color pixel_color)
{
	return (t << 24 | (255 * pixel_color.r) << 16 | (255 * pixel_color.g) << 8 | (255 * pixel_color.b));
}

int ray_color(t_ray r)
{
	t_vec unit_direction = vec_unit(r.dir);
	int t = 0.5 * (unit_direction.y + 1.0);
	return ((1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// line_length는 픽셀의 한 줄의 바이트 수이므로 y * line_length는 y번째 줄의 시작 주소를 의미한다.
	// bits_per_pixel은 픽셀의 비트 수이므로 x * (bits_per_pixel / 8)은 x번째 픽셀의 시작 주소를 의미한다.
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
