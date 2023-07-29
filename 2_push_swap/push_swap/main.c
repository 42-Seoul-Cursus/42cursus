/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2023/07/29 16:06:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_ps(t_push_swap *ps)
{
	ps->a.size = 0;
	ps->a.node[FRONT] = NULL;
	ps->a.node[REAR] = NULL;
	ps->b.size = 0;
	ps->b.node[FRONT] = NULL;
	ps->b.node[REAR] = NULL;
	ps->cnt = 0;
}

void	print_stack(t_push_swap *ps)

{
	t_stack *a = &(ps->a);
	t_stack *b = &(ps->b);
	t_stack_node	*a_tmp;
	t_stack_node	*b_tmp;
	unsigned int	i;

	i = 0;
	a_tmp = a->node[FRONT];
	b_tmp = b->node[FRONT];
	while (i < a->size || i < b->size)
	{
		if (i < a->size && a_tmp != NULL)
			ft_printf("%d\t", a_tmp->value);
		else
			ft_printf("\t");
		if (i < b->size && b_tmp != NULL)
			ft_printf("%d\n", b_tmp->value);
		else
			ft_printf("\n");
		if (a_tmp == NULL || a_tmp->next == NULL)
			;
		else
			a_tmp = a_tmp->next;
		if (b_tmp == NULL || b_tmp->next == NULL)
			;
		else
			b_tmp = b_tmp->next;
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

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	while (1)
	{
		scanf("%s", line);
		line[2] = '\n';
		flag = command(&ps, line);
		print_stack(&ps);
		if (flag == 0)
			break ;
	}

	return (0);
}
