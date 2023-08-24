/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 20:51:46 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	pipex(int ac, char *av[], char *envp[])
{
	int		(*fd)[2];
	int		i;
	int		cmd_cnt;
	char	**path;

	path = parse_path(envp);
	cmd_cnt = ac - 3;
	fd = ft_calloc(sizeof(int *) * cmd_cnt);
	infile_to_pipe();
	i = 0;
	// while (i < cmd_cnt - 1)
	// 	pipe_to_pipe();
	pipe_to_outfile();
	wait(NULL);
}
// void	pipex(int ac, char *av[], char *envp[])
// {
// 	char	**path;
// 	pid_t	pid;
// 	int		fd[2];
// 	int		file[2];

// 	path = parse_path(envp);
// 	if (pipe(fd) == -1)
// 		exit_with_err("pipe");
// 	pid = fork();
// 	if (pid == -1)
// 		exit_with_err("fork");
// 	if (pid == 0)
// 		infile_to_pipe(av, path, fd, file[0]);
// 	wait(NULL);
// 	pid = fork();
// 	if (pid == 0)
// 		pipe_to_outfile(av, path, fd, file[1]);
// 	wait(NULL);
// }

int	main(int ac, char *av[], char *envp[])
{
	if (ac < 5)
		exit_with_msg("Usage: ./pipex [infile] [cmd 1] ... [cmd n] [outfile]\n");
	pipex(ac, av, envp);
	return (0);
}
