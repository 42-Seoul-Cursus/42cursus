/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:34:01 by seunan            #+#    #+#             */
/*   Updated: 2023/08/23 20:37:36 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	buffer[8];
int		i = 0;

void	flush_buf(void)
{
	char	c;

	c = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (buffer[i] == '1')
			c += 1 << (7 - i);
	}
	ft_printf("%c", (char) c);
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		buffer[i] = '0';
	else if (signum == SIGUSR2)
		buffer[i] = '1';
	++i;
	if (i > 7)
	{
		i = 0;
		flush_buf();
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
