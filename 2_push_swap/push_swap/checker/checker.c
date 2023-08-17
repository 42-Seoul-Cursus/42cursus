/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:40:04 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 15:13:34 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	checker(&ps);
	return (0);
}

void	checker(t_push_swap *ps)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		command(ps, cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(ps) && ps->b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	command(t_push_swap *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		return (swap(&(ps->a)));
	else if (ft_strncmp(cmd, "sb\n", 4) == 0)
		return (swap(&(ps->b)));
	else if (ft_strncmp(cmd, "ss\n", 4) == 0)
		return (swap(&(ps->a)) && swap(&(ps->b)));
	else if (ft_strncmp(cmd, "pa\n", 4) == 0)
		return (push(&(ps->b), &(ps->a)));
	else if (ft_strncmp(cmd, "pb\n", 4) == 0)
		return (push(&(ps->a), &(ps->b)));
	else if (ft_strncmp(cmd, "ra\n", 4) == 0)
		return (rotate(&(ps->a), REAR));
	else if (ft_strncmp(cmd, "rb\n", 4) == 0)
		return (rotate(&(ps->b), REAR));
	else if (ft_strncmp(cmd, "rr\n", 4) == 0)
		return (rotate(&(ps->a), REAR) && rotate(&(ps->b), REAR));
	else if (ft_strncmp(cmd, "rra\n", 5) == 0)
		return (rotate(&(ps->a), FRONT));
	else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		return (rotate(&(ps->b), FRONT));
	else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		return (rotate(&(ps->a), FRONT) && rotate(&(ps->b), FRONT));
	else
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
