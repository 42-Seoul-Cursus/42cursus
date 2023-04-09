/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:28 by seunan            #+#    #+#             */
/*   Updated: 2023/03/23 17:12:49 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*answer;
	int		i;

	answer = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	i = 0;
	while (s[i] != '\0')
	{
		answer[i] = s[i];
		++i;
	}
	return (answer);
}

char	*make_backup(char *buf)
{
	char	*backup;
	int		i;
	int		j;

	i = 0;
	while (buf[i++] != '\n')
		;
	backup = ft_calloc(sizeof(char), ft_strlen(buf) - i + 1);
	j = 0;
	while (buf[i] != '\0')
		backup[j++] = buf[i++];
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	while (1)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		if (read(fd, buffer, BUFFER_SIZE) <= 0 && (backup != 0 && *backup == '\0'))
		{
			free(buffer);
			return (0);
		}
		buffer = ft_strjoin(backup, buffer);
		if (inc_newline(buffer, '\n') || )
		{
			line = make_line(buffer, '\n');
			backup = make_backup(buffer);
			break;
		}
		else
			backup = buffer;
	}
	return (line);
}
