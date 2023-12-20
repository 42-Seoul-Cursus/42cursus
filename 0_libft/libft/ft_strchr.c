/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anseungwon <anseungwon@student.42seoul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:45 by seunan            #+#    #+#             */
/*   Updated: 2023/03/19 19:36:55 by anseungwon       ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (TRUE)
	{
		if (*s == (char)c)
			return ((char *)s);
		else if (*s == '\0')
			return (NULL);
		++s;
	}
}
