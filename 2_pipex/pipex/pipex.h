/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:50:57 by seunan            #+#    #+#             */
/*   Updated: 2023/09/06 15:56:54 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <sys/fcntl.h>
# define READ_END 0
# define WRITE_END 1

// utils.c

int		open_files(char *av[]);
void	close_files(int *file);
void	protected_pipe(int fd[2]);
pid_t	protected_fork(void);
void	protected_dup2(int oldfd, int newfd);

// pipex.c

void	pipex(char *av[], char *envp[]);
void	infile_to_fd(char *av[], char *path[], int fd[2], int infile);
void	fd_to_outfile(char *av[], char *path[], int fd[2], int outfile);
char	*path_join(char *path[], char *cmd);
char	**parse_path(char *envp[]);

// err.c

void	exit_with_err(char *err);
void	exit_with_msg(char *msg);

#endif
