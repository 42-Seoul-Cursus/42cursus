#include "so_long.h"

void	up(t_vars *vars)
{
	if (vars->map[vars->player[1] - 1][vars->player[0]] == 'C')
		--(vars->ball);
	else if (vars->map[vars->player[1] - 1][vars->player[0]] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->player[1]][vars->player[0]] = '0';
	vars->map[vars->player[1] - 1][vars->player[0]] = 'P';
	vars->player[1] -= 1;
}

void	down(t_vars *vars)
{
	if (vars->map[vars->player[1] + 1][vars->player[0]] == 'C')
		--(vars->ball);
	else if (vars->map[vars->player[1] + 1][vars->player[0]] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->player[1]][vars->player[0]] = '0';
	vars->map[vars->player[1] + 1][vars->player[0]] = 'P';
	vars->player[1] += 1;
}

void	left(t_vars *vars)
{
	if (vars->map[vars->player[1]][vars->player[0] - 1] == 'C')
		--(vars->ball);
	else if (vars->map[vars->player[1]][vars->player[0] - 1] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->player[1]][vars->player[0]] = '0';
	vars->map[vars->player[1]][vars->player[0] - 1] = 'P';
	vars->player[0] -= 1;
}

void	right(t_vars *vars)
{
	if (vars->map[vars->player[1]][vars->player[0] + 1] == 'C')
		--(vars->ball);
	else if (vars->map[vars->player[1]][vars->player[0] + 1] == 'E')
	{
		if (vars->ball == 0)
			exit(0);
		return ;
	}
	vars->map[vars->player[1]][vars->player[0]] = '0';
	vars->map[vars->player[1]][vars->player[0] + 1] = 'P';
	vars->player[0] += 1;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 | keycode == 126)
		if (vars->map[vars->player[1] - 1][vars->player[0]] != '1')
			up(vars);
	if (keycode == 1 | keycode == 125)
		if (vars->map[vars->player[1] + 1][vars->player[0]] != '1')
			down(vars);
	if (keycode == 0 | keycode == 123)
		if (vars->map[vars->player[1]][vars->player[0] - 1] != '1')
			left(vars);
	if (keycode == 2 | keycode == 124)
		if (vars->map[vars->player[1]][vars->player[0] + 1] != '1')
			right(vars);
	print_map(vars, 64, 64);
	printf("%llu\n", ++(vars->cnt));
	return (0);
}

int	exit_window(t_vars *vars)
{
	(void) vars;
	exit(0);
}
