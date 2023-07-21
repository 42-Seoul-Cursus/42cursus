/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:58:00 by anseungwon        #+#    #+#             */
/*   Updated: 2023/07/21 18:20:36 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_num(unsigned long long num, int size)
{
	char	c;

	if (num == 0)
		return ;
	write_num(num / 10, size - 1);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	print_num(unsigned long long num)
{
	int					size;
	unsigned long long	tmp;

	tmp = num;
	size = 0;
	while (tmp)
	{
		tmp /= 10;
		++size;
	}
	write_num(num, size);
	write(1, "\n", 1);
}

int	exit_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}
