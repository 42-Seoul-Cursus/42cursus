/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:08:46 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 18:12:39 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_err(char *err)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(err);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}

void	exit_with_msg(char *msg)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
