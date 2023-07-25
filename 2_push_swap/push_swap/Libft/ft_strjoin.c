/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42seoul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:07:32 by seunan            #+#    #+#             */
/*   Updated: 2023/03/19 19:39:26 by anseungwon       ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	size_t	i;
	size_t	j;

	answer = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!answer)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		answer[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		answer[i++] = s2[j++];
	return (answer);
}
