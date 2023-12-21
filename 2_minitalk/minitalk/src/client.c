/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:53:29 by jooahn            #+#    #+#             */
/*   Updated: 2023/10/31 14:54:41 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

void	send_bit(pid_t pid, unsigned char bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
		send_bit(pid, (c >> i++) & 1);
}

int main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*str;

	if (ac == 3)
	{
		server_pid = (pid_t)ft_atoi(av[1]);
		str = av[2];
		while (*str)
			send_char(server_pid, *str++);
	}
	return (0);
}
