/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:31:33 by seunan            #+#    #+#             */
/*   Updated: 2023/04/09 22:57:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	find_idx(char *s, char c);
char	*ft_calloc(size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*make_backup(char *buf, size_t size);
char	*make_line(char *buf);

#endif
