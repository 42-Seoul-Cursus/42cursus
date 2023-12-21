/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:09:15 by anseungwon        #+#    #+#             */
/*   Updated: 2023/03/22 14:39:24 by seunan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *cnt);
void	ft_putstr(char *s, int *cnt);
void	print_address(long long unsigned int addr, int *cnt);
void	ft_puthex(void *addr, int *cnt);
void	ft_putnbr_write(long long n, char *base, int len, int *cnt);
void	ft_putnbr_base(long long n, char *base, int len, int *cnt);
void	sep_format(const char *format, va_list ap, int i, int *cnt);

#endif
