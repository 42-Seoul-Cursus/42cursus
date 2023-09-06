/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:51:55 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 16:53:31 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*open_files(char *av[])
{
	int		*file;

	file = (int *)ft_calloc(2, sizeof(int));
	file[0] = open(av[1], O_RDONLY);
	if (file[0] < 0)
		exit_with_err(av[1]);
	file[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file[1] < 0)
		exit_with_err(av[1]);
	return (file);
}

void	close_files(int *file)
{
	if (close(file[0]) < 0)
		exit_with_err("close");
	if (close(file[1]) < 0)
		exit_with_err("close");
	free(file);
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
