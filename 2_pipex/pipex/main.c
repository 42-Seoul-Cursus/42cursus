/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 00:48:55 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];

	if (ac != 5)
		exit_with_msg("Error: arguments\n");
	path = parse_path(envp);
	if (pipe(fd) == -1)
		exit_with_msg("Error: pipe\n");
	pid = fork();
	if (pid == 0)
		infile_to_fd(av, path, fd);
	else
	{
		pid = fork();
		if (pid == 0)
			fd_to_outfile(av, path, fd);
		wait(NULL);
	}
	return (0);
}
