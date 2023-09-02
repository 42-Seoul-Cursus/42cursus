/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/09/02 14:37:21 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int ac, char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];

	path = parse_path(envp);
	protected_pipe(fd);
	pid = protected_fork();
	if (pid == 0)
		infile_to_fd(av, path, fd);
	waitpid(pid, NULL, 0);
	pid = protected_fork();
	if (pid == 0)
		fd_to_outfile(av, path, fd);
	protected_close(fd[WRITE_END]);
	waitpid(pid, NULL, 0);
	(void) ac;
}

int	main(int ac, char *av[], char *envp[])
{
	if (ac < 5)
		exit_with_msg("Usage: ./pipex [infile] [cmd 1] ... [cmd n] [outfile]\n");
	pipex(ac, av, envp);
	return (0);
}
