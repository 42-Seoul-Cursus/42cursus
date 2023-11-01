/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:34:52 by jooahn            #+#    #+#             */
/*   Updated: 2023/11/02 00:25:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

static char	buf = 0; // check_buf를 사용할 때 필요

void	send_ack(pid_t pid)
{
	while (1)
	{
		if (kill(pid, SIGUSR1) != -1)
			return ;
	}
}

// if cnt == 0 -> buf |= 00000001
// if cnt == 1 -> buf |= 00000010
// ...
// if cnt == 7 -> buf |= 10000000
// 10000000 == -128
void	receive_bit(int signum, struct __siginfo *info, void *any)
{
	// static char		buf;
	static int		cnt;
	static char		backup_char = 'a';

	(void) any;
	if (info->si_pid == 0)
		return ;
	if (signum == SIGUSR1) // if bit is 1 -> SIGUSR1
		buf |= (1 << cnt);
	if (++cnt == 8)
	{
		if (backup_char != buf)
			printf("%d != %d\n",(int)backup_char, (int)buf);
		else
			write(1, &buf, 1);
		cnt = 0;
		buf = 0;
	}
	send_ack(info->si_pid); // send ack
}

// sigint로 buf 확인
void	check_buf(int signum)
{
	(void)signum;
	printf("buf : %d\n", (int)buf);
}

int main(void)
{
	struct sigaction	sa;

	signal(SIGINT, check_buf);
	sa.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = receive_bit; // signal handler
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("server pid is %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
