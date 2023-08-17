/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:08:11 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 19:00:26 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	exit_with_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static long long	make_num(const char *str, int min)
{
	long long	num;
	int			i;

	num = 0;
	i = 0;
	if (str[i] == 0)
		exit_with_msg();
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			exit_with_msg();
		num = num * 10 + (str[i] - '0');
		++i;
	}
	num *= min;
	if (num > 2147483647 || num < -2147483648)
		exit_with_msg();
	return (num);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			min;
	int			i;

	min = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		++i;
	}
	num = make_num(str + i, min);
	return (num);
}
