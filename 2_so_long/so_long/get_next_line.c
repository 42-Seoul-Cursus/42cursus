/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:13:27 by seunan            #+#    #+#             */
/*   Updated: 2023/07/18 14:50:53 by anseungwon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	return (repeat_read(&backup, fd, buf, size));
}

char	*repeat_read(char **backup, int fd, char *buf, int size)
{
	char	*tmp;

	while (size > 0)
	{
		buf[size] = '\0';
		if (!*backup)
			*backup = ft_strdup("");
		tmp = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = tmp;
		if (ft_strchr(*backup, '\n'))
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (size < 0)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	return (ret_line(backup));
}

char	*ret_line(char **backup)
{
	char	*line;
	char	*cut;

	line = NULL;
	if (*backup)
	{
		cut = ft_strchr(*backup, '\n');
		if (cut)
			return (update_line(backup, line, cut));
		if (**backup == '\0')
		{
			free(*backup);
			*backup = NULL;
		}
		line = *backup;
		*backup = NULL;
	}
	return (line);
}

char	*update_line(char **backup, char *line, char *cut)
{
	char	*tmp;

	tmp = ft_strdup(cut + 1);
	*(cut + 1) = '\0';
	line = ft_strdup(*backup);
	free(*backup);
	*backup = tmp;
	return (line);
}
