/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:51:55 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 21:05:10 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		open_err(outfile);
	return (fd);
}

int	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		open_err(infile);
	return (fd);
}

void	protected_close(int fd)
{
	if (close(fd) < 0)
		exit_with_err("close");
}

void	protected_pipe(int fd[2])
{
	if (pipe(fd) < 0)
		exit_with_err("pipe");
}

pid_t	protected_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_with_err("fork");
	return (pid);
}

void	protected_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		exit_with_err("dup2");
}
