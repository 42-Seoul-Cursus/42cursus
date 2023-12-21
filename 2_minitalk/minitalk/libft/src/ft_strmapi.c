/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:18:14 by seunan            #+#    #+#             */
/*   Updated: 2023/03/18 19:37:49 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	out = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		out[i] = f(i, s[i]);
		++i;
	}
	return (out);
}
