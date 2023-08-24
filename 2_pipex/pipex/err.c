/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:08:46 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 20:06:45 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_err(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	exit_with_msg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	open_err(char *file)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(file);
	exit(EXIT_FAILURE);
}
