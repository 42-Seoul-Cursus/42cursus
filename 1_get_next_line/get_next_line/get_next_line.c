/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:51:08 by seunan            #+#    #+#             */
/*   Updated: 2023/04/26 17:53:17 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line = *backup;
		*backup = NULL;
	}
	return (line);
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
	while (size > 0)
	{
		buf[size] = '\0';
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup("\0");
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (ft_strchr(backup[fd], '\n') != NULL)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ret_line(&backup[fd], size));
}
