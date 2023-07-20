/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:06 by seunan            #+#    #+#             */
/*   Updated: 2023/07/21 00:54:29 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_msg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	protected_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_msg("Error\nFailed to open");
	return (fd);
}

void	*protected_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (ptr == NULL)
		exit_with_msg("Error\nFailed to malloc");
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

char	**protected_realloc(char **ptr, size_t size, size_t len)
{
	char	**new_ptr;
	size_t	i;

	if (!ptr)
		return (protected_calloc(size));
	i = 0;
	new_ptr = protected_calloc(size);
	while (i < len)
	{
		new_ptr[i] = ptr[i];
		++i;
	}
	free(ptr);
	return (new_ptr);
}
