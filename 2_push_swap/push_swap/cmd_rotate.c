/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 03:07:20 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 03:07:51 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *ps)
{
	rotate(&(ps->a), REAR);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap *ps)
{
	rotate(&(ps->b), REAR);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_swap *ps)
{
	rotate(&(ps->a), REAR);
	rotate(&(ps->b), REAR);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_push_swap *ps)
{
	rotate(&(ps->a), FRONT);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push_swap *ps)
{
	rotate(&(ps->b), FRONT);
	ft_putstr_fd("rrb\n", 1);
}
