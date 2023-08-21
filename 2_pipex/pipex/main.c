/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:33 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 00:20:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	char	**path;
	pid_t	pid;
	int		fd[2];

	if (ac != 5)
		exit_with_msg("Error: arguments\n");
	path = parse_path(envp); 				// PATH 환경변수를 파싱하여 저장
	if (pipe(fd) == -1) 					// 파이프 생성
		exit_with_msg("Error: pipe\n");

	pid = fork();
	if (pid == 0) 							// children infile -> cmd1 -> fd[1]
		infile_to_fd(av, path, fd);
	else // parent process
	{
		pid = fork();
		if (pid == 0) 						// children fd[0] -> cmd2 -> outfile
			fd_to_outfile(av, path, fd);
		wait(NULL);
	}
	return (0);
}


