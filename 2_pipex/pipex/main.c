/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/08/21 19:50:13 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

char	**parse_path(char *envp[]);
int		valid_path(char *path[], char *cmd);

int	main(int ac, char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];
	int		infile, outfile;
	char	*execve_path;
	char	**execve_argv;

	if (ac != 4)
		exit_with_msg("Error: arguments");
	path = parse_path(envp);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		exit_with_msg("Error: input file");
	outfile = open(av[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1)
		exit_with_msg("Error: output file");
	if (pipe(fd) == -1)
		exit_with_msg("Error: pipe");

	pid = fork();
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		execve_path = ft_strjoin(path[valid_path(path, av[2])], av[2]);
		execve_argv = ft_split(av[2], ' ', '\0');
		execve(execve_path, execve_argv, NULL);
	}
	close(fd[WRITE_END]);
	// dup2(fd[READ_END], STDIN_FILENO);
	wait(NULL);
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

/*
	char	**cmd1 = ft_split(av[2], ' ');
	// char	**cmd2 = ft_split(av[3], ' ');

	char	*cmdVec1[] = {cmd1[0], cmd1[1], av[1], NULL};
	// char	*cmdVec2[] = {cmd2[0], cmd2[1], NULL};

	int		fd[2];

	pid_t	pid;

	int		file1 = open(av[1], O_RDONLY);
	// int		file2 = open(av[4], O_WRONLY | O_CREAT, 0666);

	if (ac != 5)
	{
		perror("arguments");
		return (1);
	}
	pipe(fd);
	pid = fork();

	int	flag = -1;
	int	i = 0;

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0) // child process
	{
		// dup2(fd[1], 1);
		close(fd[0]); // 자식 프로세스는 파이프에서 읽지 않으므로 읽는 쪽을 닫는다.
		while (flag < 0 || i < 5)
		{
			flag = execve("/bin/cat", cmdVec1, NULL);
			printf("flag: %d\n", flag);
			printf("%s\n", ft_strjoin(path[i], cmd1[0]));
			++i;
		}
	}
	else // parent process
	{

	}
 */
