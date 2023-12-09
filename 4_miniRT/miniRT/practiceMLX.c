#include "miniRT.h"
#include <stdlib.h>

const int WIDTH = 1440;
const int HEIGHT = 900;

// mlx 구조체
typedef struct s_vars
{
	// 그래픽 시스템에 대한 연결 설정을 위한 MLX 객체를 가리키는 포인터
	void	*mlx;
	// mlx_new_window로 만든 창에 대한 포인터 반환
	void	*win;
}			t_vars;

// image data 구조체
typedef struct s_data
{
	// 이미지 객체를 가리키는 포인터
	void	*img;
	// 픽셀을 이미지에 쓰기 위해 이미지의 주소를 가리키는 포인터
	char	*addr;

	/* 밑의 변수들은 mlx_get_data_addr에 의해 채워진다. */

	// 픽셀의 비트 수
	int		bits_per_pixel;
	// 픽셀의 한 줄의 바이트 수
	int		line_length;
	// 픽셀의 엔디안
	int		endian;
}			t_data;

//함수 선언부
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			prtimage(void);
int			create_trgb(int t, int r, int g, int b);
int			exit_hook(void);
int			key_hook(int keycode, t_vars *vars);

// main function!
int	main(void)
{
	prtimage();
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// line_length는 픽셀의 한 줄의 바이트 수이므로 y * line_length는 y번째 줄의 시작 주소를 의미한다.
	// bits_per_pixel은 픽셀의 비트 수이므로 x * (bits_per_pixel / 8)은 x번째 픽셀의 시작 주소를 의미한다.
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	prtimage(void)
{
	int		color;
	t_vars	vars;
	t_data	image;

	// 그래픽 시스템에 대한 연결 설정, MLX 객체 반환
	vars.mlx = mlx_init();

	// mlx_new_window로 만든 창에 대한 포인터 반환
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hellow World!");

	// mlx_pixel_put은 굉장히 느린 작업이므로, 이미지 객체를 만들어서 한번에 출력하는 것이 좋다.
	// image로 버퍼링을 하고, mlx_put_image_to_window로 한번에 출력한다고 생각하면 된다.
	image.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);

	// 픽셀을 이미지에 쓰기 위해 이미지의 주소를 가리키는 포인터 반환
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian); // 이미지 주소 할당

	for (int i = 0; i < HEIGHT - 1; ++i)
	{
		for (int j = 0; j < WIDTH - 1; ++j)
		{
			// 0 ~ 1 사이의 값을 r, g, b에 할당
			double r = (double)(WIDTH - j) / (WIDTH - 1);
			double g = (double)(i) / (HEIGHT - 1);
			double b = 1;
			color = create_trgb(0, r * 255.999, g * 255.999, b * 255.999);
			my_mlx_pixel_put(&image, j, i, color);
		}
	}

	// 이미지 객체를 창에 출력
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);

	// mlx_key_hook은 키보드 이벤트를 처리하는 함수이다. esc key press event
	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook은 키보드 이벤트를 처리하는 함수이다. close button press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	// mlx_loop는 이벤트를 기다리는 함수이다.
	mlx_loop(vars.mlx);
	return (0);
}

// Transparency, Red, Green, Blue
// 0xTTRRGGBB
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
