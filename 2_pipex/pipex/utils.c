/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:36:27 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 00:19:37 by seunan           ###   ########.fr       */
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

	outfile = protected_open(av[4], O_WRONLY | O_CREAT | O_TRUNC); 	// 출력 파일을 쓰기, 없으면 생성 후 열기
	protected_close(fd[WRITE_END]); 								// 자식 프로세스는 파이프에서 쓰지 않으므로 쓰는 쪽을 닫는다.
	protected_dup2(fd[READ_END], STDIN_FILENO); 					// 파이프의 읽기 쪽을 표준 입력으로 복제
	protected_dup2(outfile, STDOUT_FILENO); 						// 출력 파일을 표준 출력으로 복제
	execve_argv = ft_split(av[3], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])], execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	exit_with_msg("Error: execve\n");
}

void	infile_to_fd(char *av[], char *path[], int fd[2])
{
	int		infile;
	char	**execve_argv;
	char	*execve_path;

	infile = protected_open(av[1], O_RDONLY); 		// 입력 파일을 읽기 전용으로 열기
	protected_close(fd[READ_END]); 					// 자식 프로세스는 파이프에서 읽지 않으므로 읽는 쪽을 닫는다.
	protected_dup2(infile, STDIN_FILENO); 			// infile을 표준 입력으로 복제
	protected_dup2(fd[WRITE_END], STDOUT_FILENO); 	// 파이프의 쓰기 쪽을 표준 출력으로 복제
	execve_argv = ft_split(av[2], ' ', '\0');
	execve_path = ft_strjoin(path[valid_path(path, execve_argv[0])], execve_argv[0]);
	execve(execve_path, execve_argv, NULL);
	exit_with_msg("Error: execve\n");
}

int		valid_path(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), F_OK | X_OK) == 0)
			return (i);
		++i;
	}
	exit_with_msg("Error: command not found");
	return (-1);
}

char	**parse_path(char *envp[])
{
	char	**path = NULL;
	char	*tmp;
	int		i;

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
