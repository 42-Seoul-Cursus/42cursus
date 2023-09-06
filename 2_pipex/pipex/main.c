/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 16:53:35 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	if (ac != 5)
		exit_with_msg("Usage: ./pipex [infile] [cmd 1] ... [cmd n] [outfile]\n");
	pipex(av, envp);
	return (0);
}

void	pipex(char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];
	int		*file;

	path = parse_path(envp);
	file = open_files(av);
	protected_pipe(fd);
	pid = protected_fork();
	if (pid == 0)
		infile_to_fd(av, path, fd, file[0]);
	waitpid(pid, NULL, 0);
	pid = protected_fork();
	if (pid == 0)
		fd_to_outfile(av, path, fd, file[1]);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(pid, NULL, 0);
	close_files(file);
	free_path(path);
}
