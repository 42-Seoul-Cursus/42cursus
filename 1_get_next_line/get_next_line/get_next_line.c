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
	static char	*backup;
	char		*buf;
	char		*line;
	int			size;

	if (backup == 0)
		backup = ft_calloc(1);
	while (1)
	{
		if (*backup != '\0')
		{
			if (find_idx(backup, '\n') > 0)
			{
				line = make_line(backup);
				backup = make_backup(backup, 1000); // size 써야댐
				return (line);
			}
		}
		while (1)
		{
			buf = ft_calloc((BUFFER_SIZE + 1));
			size = read(fd, buf, BUFFER_SIZE);
			if (size == 0 && *buf == '\0')
			{
				free(buf);
				return (backup);
			}
			buf = ft_strjoin(backup, buf);
			if (find_idx(buf, '\n') > 0)
			{
				line = make_line(buf);
				backup = make_backup(buf, 1000);
				return (line);
			}
			backup = make_backup(buf, 1000);
			if (size == 0 && *backup == '\0')
				return (0);
		}
	}
	return (line);
}
