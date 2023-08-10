/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:09:06 by seunan            #+#    #+#             */
/*   Updated: 2023/08/11 02:09:17 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_push_swap *ps)
{
	ps->a.size = 0;
	ps->a.node[FRONT] = NULL;
	ps->a.node[REAR] = NULL;
	ps->b.size = 0;
	ps->b.node[FRONT] = NULL;
	ps->b.node[REAR] = NULL;
	ps->sum = 0;
}
