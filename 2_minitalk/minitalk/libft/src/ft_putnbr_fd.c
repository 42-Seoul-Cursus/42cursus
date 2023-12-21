/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:21:05 by seunan            #+#    #+#             */
/*   Updated: 2023/03/20 17:43:29 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_num(int n, int fd)
{
	char	num;

	if (n == 0)
		return ;
	num = n % 10 + '0';
	print_num(n / 10, fd);
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	last;

	if (n > 0)
		print_num(n, fd);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		last = -1 * (n % 10) + '0';
		n /= 10;
		write(fd, "-", 1);
		print_num(-n, fd);
		write(fd, &last, 1);
	}
}
