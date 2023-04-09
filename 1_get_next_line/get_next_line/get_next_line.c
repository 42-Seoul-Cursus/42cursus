/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:31:33 by seunan            #+#    #+#             */
/*   Updated: 2023/04/09 23:05:58 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	**head;
	t_list			*backup;
	char			*buf;
	char			*line;
	long long		size;

	if (head == 0)
		head = malloc(sizeof(t_list **) * 1);
	backup = set_backup(head, fd);
	while (1)
	{
		if (backup->content != 0)
		{
			size = check_nl(backup->content, backup->size);
			if (size > 0)
			{
				line = make_line(backup->content, size);
				make_backup(backup, backup->size - size, backup->content);
				break ;
			}
		}
		else
		{
			buf = malloc(sizeof(char) * BUFFER_SIZE);
			size = read(fd, buf, BUFFER_SIZE);
			buf = make_buf(backup, buf, &size);
			if (check_nl(buf, size) > 0)
			{
				line = make_line(buf, check_nl(buf, size));
				make_backup(backup, size, buf);
				break ;
			}
		}
	}
	return (line);
}

t_list	*set_backup(t_list **head, int fd)
{
	t_list	*tmp;

	if (fd < 0)
		return (0);
	if (*head == (void *)0)
	{
		*head = malloc(sizeof(t_list) * 1);
		tmp = *head;
		tmp->fd = fd;
		tmp->content = (void *)0;
		tmp->size = 0;
	}
	tmp = *head;
	while (tmp->fd != fd && tmp->next != 0)
		tmp = tmp->next;
	if (tmp->fd != fd && tmp->next == 0)
	{
		tmp->next = malloc(sizeof(t_list) * 1);
		tmp = tmp->next;
		tmp->fd = fd;
		tmp->content = (void *)0;
		tmp->size = 0;
	}
	return (tmp);
}
