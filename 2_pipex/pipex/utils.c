/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:27 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 16:54:22 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	infile_to_fd(char *av[], char *path[], int fd[2], int infile)
{
	char	**execve_argv;
	char	*execve_path;

	if (close(fd[READ_END]) < 0)
		exit_with_err("close");
	execve_argv = ft_split(av[2], ' ', '\0');
	execve_path = path_join(path, execve_argv[0]);
	protected_dup2(infile, STDIN_FILENO);
	protected_dup2(fd[WRITE_END], STDOUT_FILENO);
	if (execve(execve_path, execve_argv, NULL) < 0)
		exit_with_msg(ft_strjoin(av[2], ": command not found\n"));
}

void	fd_to_outfile(char *av[], char *path[], int fd[2], int outfile)
{
	char	**execve_argv;
	char	*execve_path;

	if (close(fd[WRITE_END]) < 0)
		exit_with_err("close");
	execve_argv = ft_split(av[3], ' ', '\0');
	execve_path = path_join(path, execve_argv[0]);
	protected_dup2(fd[READ_END], STDIN_FILENO);
	protected_dup2(outfile, STDOUT_FILENO);
	if (execve(execve_path, execve_argv, NULL) < 0)
		exit_with_msg(ft_strjoin(av[3], ": command not found\n"));
}

char	*path_join(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), X_OK) == 0)
			break ;
		++i;
	}
	if (path[i] == NULL)
		return (cmd);
	return (ft_strjoin(path[i], cmd));
}

char	**parse_path(char *envp[])
{
	char	**path;
	char	*tmp;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			path = ft_split(tmp, ':', '/');
			free(tmp);
			break ;
		}
		++i;
	}
	return (path);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		++i;
	}
	free(path);
}
