/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:47:24 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 03:08:18 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
