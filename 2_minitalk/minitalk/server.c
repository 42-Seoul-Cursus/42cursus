/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:34:01 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 17:43:19 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("SIGUSR1\n", 1);
	else if (signum == SIGUSR2)
		ft_putstr_fd("SIGUSR2\n", 1);
	else
		ft_putstr_fd("Unknown signal\n", 1);
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
