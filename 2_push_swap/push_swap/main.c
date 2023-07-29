/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/29 15:01:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

t_stack_node	*new_node(int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
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
			enque(&ps->a, REAR, new_node(ft_atoi(tmp[j])));
			++j;
			++ps->cnt;
		}
	}
}

int	main(int ac, char *av[])
{
	t_push_swap	ps;
	int			flag;
	char		*line = (char *)calloc(sizeof(char), 4);

	parse_arg(&ps, ac, av);
	while (1)
	{
		scanf("%s", line);
		line[2] = '\n';
		flag = command(&ps, line);
		print_stack(&ps.a);
		print_stack(&ps.b);
		if (flag == 0)
			break ;
	}

	return (0);
}
