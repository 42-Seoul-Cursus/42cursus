#include "miniRT.h"

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	/* ~~Ray tracing~~ */

	// Image
	double aspect_ratio = 16.0 / 9.0; // 화면의 비율
	int image_width = 400;
	int image_height = (int)((double)image_width / aspect_ratio);

	// Camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0; // ray를 쏠 위치와 viewport까지의 최단거리이다. 즉 viewport의 중점과 ray의 원점을 이은 거리이다.

	t_vec origin = vec(0, 0, 0);
	t_vec horizontal = vec(viewport_width, 0, 0);
	t_vec vertical = vec(0, viewport_height, 0);
	t_vec lower_left_corner =
	vec(origin.x + (- horizontal.x / 2) + (-vertical.x / 2) + (0)
		 ,origin.y + (- horizontal.y / 2) + (-vertical.y / 2) + (0)
		 ,origin.z + (- horizontal.z / 2) + (-vertical.z / 2) + (-focal_length));

	t_ray r;
	r.origin = vec(0, 0, 0); // 3차원상의 정점 좌표
	// r.dir = // 방향벡터
	// vec(lower_left_corner.x + u*horizontal.x + v*vertical.x - origin.x,
	// 		lower_left_corner.y + u*horizontal.y + v*vertical.y - origin.y,
	// 		lower_left_corner.z + u*horizontal.z + v*vertical.z - origin.z);

	/* ~~Ray Tracing */

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L<<17, exit_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
