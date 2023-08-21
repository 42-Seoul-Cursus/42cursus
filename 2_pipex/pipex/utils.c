/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:27 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 00:44:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	fd_to_outfile(char *av[], char *path[], int fd[2])
{
	int		outfile;
	char	**execve_argv;
	char	*execve_path;

	outfile = protected_open(av[4], O_WRONLY | O_CREAT | O_TRUNC);
	protected_close(fd[WRITE_END]);
	protected_dup2(fd[READ_END], STDIN_FILENO);
	protected_dup2(outfile, STDOUT_FILENO);
	execve_argv = ft_split(av[3], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	exit_with_msg("Error: execve\n");
}

void	infile_to_fd(char *av[], char *path[], int fd[2])
{
	int		infile;
	char	**execve_argv;
	char	*execve_path;

	infile = protected_open(av[1], O_RDONLY);
	protected_close(fd[READ_END]);
	protected_dup2(infile, STDIN_FILENO);
	protected_dup2(fd[WRITE_END], STDOUT_FILENO);
	execve_argv = ft_split(av[2], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	exit_with_msg("Error: execve\n");
}

int	valid_path(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), F_OK | X_OK) == 0)
			return (i);
		++i;
	}
	exit_with_msg("Error: command not found\n");
	return (-1);
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
