/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:12:15 by anseungwon        #+#    #+#             */
/*   Updated: 2023/08/23 19:21:17 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	++(*cnt);
}

void	sep_format(const char *format, va_list ap, int i, int *cnt)
{
	if (format[i] == 'c')
		ft_putchar(va_arg(ap, int), cnt);
	else if (format[i] == 's')
		ft_putstr(va_arg(ap, char *), cnt);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", 10, cnt);
	else if (format[i] == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", 16, cnt);
	else if (format[i] == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", 16, cnt);
	else if (format[i] == 'p')
		ft_puthex(va_arg(ap, void *), cnt);
	else if (format[i] == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", 10, cnt);
	else if (format[i] == '%')
		ft_putchar('%', cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			sep_format(format, ap, i, &cnt);
		}
		else
			ft_putchar(format[i], &cnt);
		++i;
	}
	va_end(ap);
	return (cnt);
}
