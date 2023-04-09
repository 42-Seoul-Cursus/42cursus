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

typedef struct s_list
{
	char			*content;
	size_t			size;
	int				fd;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
t_list				*set_backup(t_list **head, int fd);
size_t				check_nl(char *buf, size_t size);
char				*make_line(char *buf, size_t size);
void				make_backup(t_list *backup, size_t size, char *buf);
char				*make_buf(t_list *backup, char *buf, long long *size);

#endif
