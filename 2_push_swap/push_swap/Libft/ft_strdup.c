/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:08:57 by seunan            #+#    #+#             */
/*   Updated: 2023/03/23 04:48:49 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*answer;
	size_t	i;

	answer = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (!answer)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		answer[i] = s1[i];
		++i;
	}
	return (answer);
}
