/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:29:58 by seunan            #+#    #+#             */
/*   Updated: 2023/07/21 01:02:21 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		x;
	int		y;
	int		p[2];
	int		fd;
	int		cnt;
	int		ball;
	int		is_escape;
}			t_vars;

void		xpm_file_to_img(t_vars *vars, int width, int height, char tmp);
void		print_map(t_vars *vars, int width, int height);
void		set_vars(t_vars *vars);
int			protected_open(char *path);
void		*protected_calloc(size_t size);
char		**protected_realloc(char **ptr, size_t size, size_t len);
char		**dup_map(t_vars *vars);
void		parse_map(t_vars *vars);
void		exit_with_msg(char *msg);
void		free_map(char **visited);
void		dfs_find_c(t_vars *vars, int x, int y, char **visited);
void		dfs_find_e(t_vars *vars, int x, int y, char **visited);
void		is_valid_arg(int ac, char *av);
void		is_valid_map(t_vars *vars);
void		is_rectangular(t_vars *vars);
void		is_escape(t_vars *vars);
void		is_dup_char(t_vars *vars);
void		is_valid_char(t_vars *vars);
void		is_map_around_one(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
void		up(t_vars *vars);
void		down(t_vars *vars);
void		left(t_vars *vars);
void		right(t_vars *vars);
void		write_num(unsigned long long num, int size);
void		print_num(unsigned long long num);
int			exit_window(t_vars *vars);
char		*get_next_line(int fd);
char		*repeat_read(char **backup, int fd, char *buf, int size);
char		*ret_line(char **backup);
char		*update_line(char **backup, char *line, char *cut);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);

#endif
