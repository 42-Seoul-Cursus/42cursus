/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:33:32 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 17:44:20 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_with_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	if (ac != 3)
		exit_with_msg("Usage: ./client [PID] [MESSAGE]\n");
	if (ft_strncmp("a", av[2], 1))
		kill(ft_atoi(av[1]), SIGUSR1);
	else if (ft_strncmp("b", av[2], 1))
		kill(ft_atoi(av[1]), SIGUSR2);
	return (0);
}
