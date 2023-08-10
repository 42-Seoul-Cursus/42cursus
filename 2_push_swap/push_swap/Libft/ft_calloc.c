/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:08:46 by seunan            #+#    #+#             */
/*   Updated: 2023/08/10 23:12:11 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	mem = malloc(size * count);
	if (!mem)
	{
		ft_putstr_fd("Error : malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(mem, size * count);
	return ((void *) mem);
}
