/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:13:27 by seunan            #+#    #+#             */
/*   Updated: 2023/05/02 15:58:11 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ret_line(char **backup, int size)
{
	char	*line;
	char	*cut;

	line = NULL;
	if (size < 0)
		return (NULL);
	if (*backup)
	{
		cut = ft_strchr(*backup, '\n');
		if (cut != NULL)
			return (update_line(backup, line, cut));
		if (**backup == '\0')
		{
			free(*backup);
			return (NULL);
		}
		line = *backup;
		*backup = NULL;
	}
	return (line);
}

char	*make_backup(char **backup, int fd, char *buf, int size)
{
	char	*tmp;

	while (size > 0)
	{
		buf[size] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		tmp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = tmp;
		if (ft_strchr(backup[fd], '\n') != NULL)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (size == -1)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	return (ret_line(&backup[fd], size));
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	return (make_backup(backup, fd, buf, size));
}
