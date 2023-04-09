/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:15 by seunan            #+#    #+#             */
/*   Updated: 2023/03/23 15:08:23 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*make_backup(char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*make_line(char *buf, char c);
char	*ft_calloc(size_t count, size_t size);
int		inc_newline(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
