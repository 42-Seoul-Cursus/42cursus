/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:47:24 by seunan            #+#    #+#             */
/*   Updated: 2023/08/13 21:19:17 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_push_swap *ps)
{
	swap(&(ps->a));
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_swap *ps)
{
	swap(&(ps->b));
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_swap *ps)
{
	swap(&(ps->a));
	swap(&(ps->b));
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_push_swap *ps)
{
	push(&(ps->b), &(ps->a));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_push_swap *ps)
{
	push(&(ps->a), &(ps->b));
	ft_putstr_fd("pb\n", 1);
}

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

void	rrr(t_push_swap *ps)
{
	rotate(&(ps->a), FRONT);
	rotate(&(ps->b), FRONT);
	ft_putstr_fd("rrr\n", 1);
}

