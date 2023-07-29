/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:40:04 by seunan            #+#    #+#             */
/*   Updated: 2023/07/29 16:10:43 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;
	int			flag;
	char		*line[5];

	init_ps(&ps);
	parse_arg(&ps, ac, av);
	while (1)
	{
		scanf("%s", line);
		if (ft_strlen(line) == 3)
			line[2] = '\n';
		else if (ft_strlen(line) == 4)
			line[3] = '\n';
		flag = command(&ps, line);
		print_stack(&ps.a);
		print_stack(&ps.b);
		if (flag == 0)
			break ;
	}
	return (0);
}
