/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:53:36 by jooahn            #+#    #+#             */
/*   Updated: 2023/10/31 14:54:51 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int signum)
{
	static int	cnt;
	static char	buf;

	if (signum == SIGUSR1)
		buf |= (1 << cnt);
	if (++cnt == 8)
	{
		write(1, &buf, 1);
		cnt = 0;
		buf = 0;
	}

}

int main(void)
{
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	ft_printf("server pid is %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
