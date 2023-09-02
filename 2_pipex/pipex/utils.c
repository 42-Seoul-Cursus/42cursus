/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:27 by seunan            #+#    #+#             */
/*   Updated: 2023/09/02 14:41:11 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_to_outfile(char *av[], char *path[], int fd[2])
{
	int		outfile;
	char	**execve_argv;
	char	*execve_path;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile < 0)
		exit_with_msg("Error: output file\n");
	protected_close(fd[WRITE_END]);
	execve_argv = ft_split(av[3], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);

	protected_dup2(fd[READ_END], STDIN_FILENO);
	protected_dup2(outfile, STDOUT_FILENO);
	execve(execve_path, execve_argv, NULL);
	execve(execve_argv[0], execve_argv, NULL);
}

void	infile_to_fd(char *av[], char *path[], int fd[2])
{
	int		infile;
	char	**execve_argv;
	char	*execve_path;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		exit_with_err(av[1]);
	protected_close(fd[READ_END]);
	protected_dup2(infile, STDIN_FILENO);
	protected_dup2(fd[WRITE_END], STDOUT_FILENO);
	execve_argv = ft_split(av[2], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])],
			execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	execve(execve_argv[0], execve_argv, NULL);
}

int	valid_path(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), X_OK) == 0)
			break;
		++i;
	}
	return (i);
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
