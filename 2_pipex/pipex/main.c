/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 18:12:15 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leak(void)
{
	system("leaks pipex > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}

int	main(int ac, char *av[], char *envp[])
{
	atexit(leak);
	if (ac != 5)
		exit_with_msg("Usage: ./pipex [infile] [cmd 1] ... [cmd n] [outfile]\n");
	pipex(av, envp);
	return (0);
}
