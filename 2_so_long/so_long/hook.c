/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:30:16 by seunan            #+#    #+#             */
/*   Updated: 2023/07/20 18:13:14 by seunan           ###   ########.fr       */
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
	int size;
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

void	up(t_vars *vars)
{
	if (vars->map[vars->p[1] - 1][vars->p[0]] == 'C')
		--(vars->ball);
	else if (vars->map[vars->p[1] - 1][vars->p[0]] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1] - 1][vars->p[0]] = 'P';
	vars->p[1] -= 1;
	print_num(++vars->cnt);
}

void	down(t_vars *vars)
{
	if (vars->map[vars->p[1] + 1][vars->p[0]] == 'C')
		--(vars->ball);
	else if (vars->map[vars->p[1] + 1][vars->p[0]] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1] + 1][vars->p[0]] = 'P';
	vars->p[1] += 1;
	print_num(++vars->cnt);
}

void	left(t_vars *vars)
{
	if (vars->map[vars->p[1]][vars->p[0] - 1] == 'C')
		--(vars->ball);
	else if (vars->map[vars->p[1]][vars->p[0] - 1] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1]][vars->p[0] - 1] = 'P';
	vars->p[0] -= 1;
	print_num(++vars->cnt);
}

void	right(t_vars *vars)
{
	if (vars->map[vars->p[1]][vars->p[0] + 1] == 'C')
		--(vars->ball);
	else if (vars->map[vars->p[1]][vars->p[0] + 1] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->p[1]][vars->p[0]] = '0';
	vars->map[vars->p[1]][vars->p[0] + 1] = 'P';
	vars->p[0] += 1;
	print_num(++vars->cnt);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		if (vars->map[vars->p[1] - 1][vars->p[0]] != '1')
			up(vars);
	if (keycode == 1)
		if (vars->map[vars->p[1] + 1][vars->p[0]] != '1')
			down(vars);
	if (keycode == 0)
		if (vars->map[vars->p[1]][vars->p[0] - 1] != '1')
			left(vars);
	if (keycode == 2)
		if (vars->map[vars->p[1]][vars->p[0] + 1] != '1')
			right(vars);
	print_map(vars, 64, 64);
	return (0);
}

int	exit_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
