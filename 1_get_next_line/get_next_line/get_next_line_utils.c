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

char	*ft_calloc(size_t size)
{
	char	*answer;
	size_t	i;

	answer = malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		answer[i] = '\0';
		++i;
	}
	return (answer);
}

size_t	find_idx(char *s, char c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		while (s[i] != '\0')
			++i;
	else if (c == '\n')
	{
		while (s[i] != '\0')
		{
			if (s[i] == '\n')
				return (i);
			++i;
		}
		return (0);
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = ft_calloc((find_idx(s1, '\0') + find_idx(s2, '\0') + 1));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		++i;
	}
	while (s2[j] != '\0')
	{
		s[i] = s2[j];
		++i;
		++j;
	}
	free(s1);
	free(s2);
	return (s);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*answer;

	answer = ft_calloc((find_idx(s, '\0') + 1));
	i = 0;
	while (s[i] != '\0')
	{
		answer[i] = s[i];
		++i;
	}
	return (answer);
}

char	*make_backup(char *buf, size_t size)
{
	char	*backup;
	size_t	i;
	size_t	j;
	size_t	flag;

	flag = (find_idx(buf, '\n') > 0);
	(void)size;
	backup = ft_calloc(find_idx(buf, '\0') - find_idx(buf, '\n') + flag);
	i = 0;
	j = find_idx(buf, '\n') + flag;
	while (buf[j] != '\0')
	{
		backup[i] = buf[j];
		++i;
		++j;
	}
	free(buf);
	return (backup);
}

char	*make_line(char *buf)
{
	char	*line;
	size_t	i;

	line = ft_calloc(find_idx(buf, '\n') + 2);
	i = 0;
	while (i <= find_idx(buf, '\n'))
	{
		line[i] = buf[i];
		++i;
	}
	return (line);
}
