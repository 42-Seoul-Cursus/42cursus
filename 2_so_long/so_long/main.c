#include <mlx.h>
#include <unistd.h>
#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(void)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}
