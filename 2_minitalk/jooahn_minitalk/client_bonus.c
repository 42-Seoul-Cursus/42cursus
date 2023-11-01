/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:34:58 by jooahn            #+#    #+#             */
/*   Updated: 2023/11/01 16:05:22 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_ack_received;

void	receive_ack()
{
	g_ack_received = 1;
}

void	send_bit(pid_t pid, unsigned char bit)
{
	while (1)
	{
		if (bit == 1)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		usleep(TIMEOUT); // if timeout -> send bit again, else -> receive ack
		usleep(100); // @test 31, 46번째 줄의 usleep이 없으면 비트가 더 보내지는 현상 생김
		if (g_ack_received)
			return ;
	}
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		send_bit(pid, (c >> i++) & 1); // 1bit씩 보내기
		// usleep(100); @test 31, 46번째 줄의 usleep이 없으면 비트가 더 보내지는 현상 생김
	}
}

int main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*str;

	if (ac == 3)
	{
		signal(SIGUSR1, receive_ack); // server로부터 ack 받기
		server_pid = (pid_t)ft_atoi(av[1]);
		str = av[2];
		while (*str)
			send_char(server_pid, *str++); // 한글자씩 보내기
	}
	return (0);
}
