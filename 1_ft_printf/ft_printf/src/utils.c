/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:34:03 by seunan            #+#    #+#             */
/*   Updated: 2023/08/23 19:21:24 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *cnt)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		*cnt += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], cnt);
		++i;
	}
}

void	print_address(long long unsigned int addr, int *cnt)
{
	if (addr == 0)
		return ;
	print_address(addr / 16, cnt);
	ft_putchar("0123456789abcdef"[addr % 16], cnt);
}

void	ft_puthex(void *addr, int *cnt)
{
	ft_putstr("0x", cnt);
	if (addr == 0)
	{
		ft_putchar('0', cnt);
		return ;
	}
	print_address((long long unsigned int) addr, cnt);
}

void	ft_putnbr_write(long long n, char *base, int len, int *cnt)
{
	if (n == 0)
		return ;
	ft_putnbr_write(n / len, base, len, cnt);
	ft_putchar(base[n % len], cnt);
}

void	ft_putnbr_base(long long n, char *base, int len, int *cnt)
{
	char	tmp;

	if (n == 0)
		ft_putchar('0', cnt);
	else if (n > 0)
		ft_putnbr_write(n, base, len, cnt);
	else
	{
		ft_putchar('-', cnt);
		tmp = (n % len) * -1 + '0';
		n /= 10;
		ft_putnbr_write(-1 * n, base, len, cnt);
		ft_putchar(tmp, cnt);
	}
}
