/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:51:08 by seunan            #+#    #+#             */
/*   Updated: 2023/04/26 16:49:22 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1048575
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ret_line(char **backup, int size);
char	*update_line(char **backup, char *line, char *cut);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);

#endif
