/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:27 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 20:50:50 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	pipe_to_outfile(char *av[], char *path[], int fd[2], int outfile)
// {
// 	char	**execve_argv;
// 	char	*execve_path;

// 	protected_close(fd[WRITE_END]);
// 	protected_dup2(fd[READ_END], STDIN_FILENO);
// 	protected_dup2(outfile, STDOUT_FILENO);
// 	execve_argv = ft_split(av[3], ' ', '\0');
// 	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
// 			execve_argv[0]);
// 	execve(execve_path, execve_argv, NULL);
// 	exit_with_msg("Error: execve\n");
// }

void	pipe_to_outfile(char *av[], char *path[], int fd[2], int outfile)
{
	char	**execve_argv;
	char	*execve_path;

	protected_close(fd[WRITE_END]);
	protected_dup2(fd[READ_END], STDIN_FILENO);
	protected_dup2(outfile, STDOUT_FILENO);
	execve_argv = ft_split(av[3], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	exit_with_msg("Error: execve\n");
}

// void	infile_to_pipe(char *av[], char *path[], int fd[2], int infile)
// {
// 	char	**execve_argv;
// 	char	*execve_path;

// 	protected_close(fd[READ_END]);
// 	protected_dup2(infile, STDIN_FILENO);
// 	protected_dup2(fd[WRITE_END], STDOUT_FILENO);
// 	execve_argv = ft_split(av[2], ' ', '\0');
// 	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
// 			execve_argv[0]);
// 	execve(execve_path, execve_argv, NULL);
// 	exit_with_msg("Error: execve\n");
// }

void	execute(int read[2], int write[2], char *cmd, char *path[])
{
	char	**execve_argv;
	char	*execve_path;

	protected_dup2(read[READ_END], STDIN_FILENO);
	protected_dup2(write[WRITE_END], STDOUT_FILENO);
	execve_argv = ft_split(cmd, ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	execve(execve_argv[0], execve_argv, NULL);
}

void	infile_to_pipe(char *av[], char *path[])
{
	pid_t	pid;
	int		fd[2];

	protected_pipe(fd);
	pid = protected_fork();
	if (pid == 0)
		execute(fd, av[2], fd[WRITE_END], path);
}

int	valid_path(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), X_OK) == 0)
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
	if (path == NULL)
		exit_with_msg("Error: PATH not found\n");
	return (path);
}
