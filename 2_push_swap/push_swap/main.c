/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/27 17:28:30 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *st)
{
	t_stack_node	*tmp;
	unsigned int	i;

	i = 0;
	tmp = st->node[FRONT];
	while (i < st->size)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
		++i;
	}
	ft_printf("\n");
}

void	parse_arg(t_push_swap *ps, int ac, char *av[])
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (++i < ac)
	{
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			push(&ps->a, ft_atoi(tmp[j]));
			++j;
			++ps->cnt;
		}
	}
}

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	parse_arg(&ps, ac, av);
	print_stack(&ps.a);
	return (0);
}
