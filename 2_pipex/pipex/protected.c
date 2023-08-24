/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:51:55 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 15:55:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	protected_close(int fd)
{
	if (close(fd) < 0)
		exit_with_msg("close error\n");
}

void	protected_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		exit_with_msg("dup2 error\n");
}
