/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:29:19 by seunan            #+#    #+#             */
/*   Updated: 2023/03/20 17:49:56 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	else if (len > ft_strlen(s) - start)
		str = ft_calloc(sizeof(char), ft_strlen(s) - start + 1);
	else
		str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		++i;
		++start;
	}
	return (str);
}
