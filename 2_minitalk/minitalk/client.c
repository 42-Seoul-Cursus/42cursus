/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:33:32 by seunan            #+#    #+#             */
/*   Updated: 2023/08/23 20:35:05 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	convert_to_bit(int pid, char word)
{
	char	mask;
	char	i;

	i = 0;
	while (i < 8)
	{
		mask = 0x80 >> i;
		if (word & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		++i;
	}
}

void	exit_with_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	char	*msg;
	int		pid;

	if (ac != 3)
		exit_with_msg("Usage: ./client [PID] [MESSAGE]\n");
	pid = ft_atoi(av[1]);
	msg = av[2];
	for (size_t i = 0; i < ft_strlen(msg); i++)
		convert_to_bit(pid, msg[i]);

	return (0);
}
