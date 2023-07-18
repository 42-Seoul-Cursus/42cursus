#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_data			img;
	int				fd;
}					t_vars;

// src.c
void				*ft_calloc(size_t count, size_t size);

// parse.c
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew_idx(void *content, int idx);
void				parse_map(t_list **map, t_vars *vars);

// hook.c
int					key_hook(int keycode, t_vars *vars);
int					mouse_click_hook(int keycode, int x, int y, t_vars *vars);
int					key_press(int keycode, t_vars *vars);

// gnl
char				*get_next_line(int fd);
char				*repeat_read(char **backup, int fd, char *buf, int size);
char				*ret_line(char **backup);
char				*update_line(char **backup, char *line, char *cut);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);

#endif
