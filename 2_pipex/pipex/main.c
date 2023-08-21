/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/08/21 20:43:37 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];
	int		infile, outfile;
	char	*execve_path;
	char	**execve_argv;

	if (ac != 5)
		exit_with_msg("Error: arguments");
	path = parse_path(envp); // PATH 환경변수를 파싱하여 저장
	if (pipe(fd) == -1) // 파이프 생성
		exit_with_msg("Error: pipe");

	pid = fork();
	if (pid == 0) // infile -> cmd1 -> fd[1]
	{
		infile = open(av[1], O_RDONLY); // 입력 파일을 읽기 전용으로 열기
		if (infile == -1)
			exit_with_msg("Error: input file");
		close(fd[READ_END]); // 자식 프로세스는 파이프에서 읽지 않으므로 읽는 쪽을 닫는다.
		dup2(infile, STDIN_FILENO); // infile을 표준 입력으로 복제
		dup2(fd[WRITE_END], STDOUT_FILENO); // 파이프의 쓰기 쪽을 표준 출력으로 복제
		execve_path = ft_strjoin(path[valid_path(path, av[2])], av[2]);
		execve_argv = ft_split(av[2], ' ', '\0');
		execve(execve_path, execve_argv, NULL);
	}
	else // parent process
	{
		pid = fork();
		if (pid == 0) // fd[0] -> cmd2 -> outfile
		{
			outfile = open(av[4], O_WRONLY | O_CREAT, 0666); // 출력 파일을 쓰기, 없으면 생성 후 열기
			if (outfile == -1)
				exit_with_msg("Error: output file");
			close(fd[WRITE_END]);
			dup2(fd[READ_END], STDIN_FILENO); // 파이프의 읽기 쪽을 표준 입력으로 복제
			dup2(outfile, STDOUT_FILENO); // 출력 파일을 표준 출력으로 복제
			execve_path = ft_strjoin(path[valid_path(path, av[3])], av[3]);
			execve_argv = ft_split(av[3], ' ', '\0');
			execve(execve_path, execve_argv, NULL);
		}
		wait(NULL);
	}
	return (0);
}

int		valid_path(char *path[], char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(ft_strjoin(path[i], cmd), F_OK) == 0)
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
