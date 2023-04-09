/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:18 by seunan            #+#    #+#             */
/*   Updated: 2023/03/23 14:44:16 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_buf(t_list *backup, char *buf, long long *size)
{
	char	*new_buf;
	size_t	i;
	size_t	j;

	new_buf = malloc(sizeof(char) * (backup->size + *size));
	i = 0;
	while (i < backup->size)
	{
		new_buf[i] = backup->content[i];
		++i;
	}
	j = 0;
	while (j < (size_t) *size)
	{
		new_buf[i] = buf[j];
		++j;
		++i;
	}
	free(buf);
	free(backup->content);
	*size += backup->size;
	return (new_buf);
}

void	make_backup(t_list *backup, size_t size, char *buf)
{
	size_t	i;
	size_t	start;

	if (backup->content != 0)
		free(backup->content);
	start = check_nl(buf, size) + 1;
	backup->content = malloc(sizeof(char) * (size - start));
	if (!(backup->content))
		return ;
	i = 0;
	if (size > start)
	{
		backup->size = size - start;
		size -= start;
	}
	while (i < size)
	{
		backup->content[i] = buf[start];
		++i;
		++start;
	}
}

char	*make_line(char *buf, size_t size)
{
	char	*line;
	size_t	i;

	line = malloc(sizeof(char) * size + 2);
	if (!line)
		return (0);
	i = 0;
	while (i <= size)
	{
		line[i] = buf[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

size_t	check_nl(char *buf, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		if (buf[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}
