/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:50:57 by seunan            #+#    #+#             */
/*   Updated: 2023/09/02 14:04:39 by seunan           ###   ########.fr       */
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

void	fd_to_outfile(char *av[], char *path[], int fd[2]);
void	infile_to_fd(char *av[], char *path[], int fd[2]);
int	valid_path(char *path[], char *cmd);
char	**parse_path(char *envp[]);

// protected.c

int		open_outfile(char *outfile);
int		open_infile(char *infile);
void	protected_close(int fd);
void	protected_pipe(int fd[2]);
void	protected_dup2(int oldfd, int newfd);
pid_t	protected_fork(void);

// err.c

void	exit_with_err(char *err);
void	exit_with_msg(char *msg);
void	open_err(char *file);

void	pipex(int ac, char *av[], char *envp[]);

#endif
