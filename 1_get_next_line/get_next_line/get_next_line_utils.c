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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

char	*make_line(char *buf, char c)
{
	char	*line;
	int		i;

	i = 0;
	while (buf[i] != c)
		++i;
	line = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (buf[i] != c)
	{
		line[i] = buf[i];
		++i;
	}
	line[i] = c;
	return (line);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	i = 0;
	while (i < size * count)
	{
		mem[i] = 0;
		++i;
	}
	return ((char *) mem);
}

int	inc_newline(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (1);
		++s;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	size_t	i;
	size_t	j;

	if (s1 == 0)
		return (ft_strdup(s2));
	answer = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!answer)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		answer[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		answer[i++] = s2[j++];
	free(s1);
	free(s2);
	return (answer);
}
