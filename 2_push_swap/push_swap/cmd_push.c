/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 03:06:23 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 03:08:26 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rrr(t_push_swap *ps)
{
	rotate(&(ps->a), FRONT);
	rotate(&(ps->b), FRONT);
	ft_putstr_fd("rrr\n", 1);
}
