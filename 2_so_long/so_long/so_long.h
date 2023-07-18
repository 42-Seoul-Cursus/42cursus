#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
	int		x;
	int		y;
	int		width;
	int		height;
	t_data	img;
	int		fd;
}			t_vars;

// parse.c
void		parse_map(t_list **map, t_vars *vars);
void		print_map(t_list **map, t_vars *vars);
void		set_vars(t_vars *vars);

// hook.c
int			key_hook(int keycode, t_vars *vars);
int			exit_window(t_vars *vars);

// get_next_line.c
char		*get_next_line(int fd);
char		*repeat_read(char **backup, int fd, char *buf, int size);
char		*ret_line(char **backup);
char		*update_line(char **backup, char *line, char *cut);

#endif
