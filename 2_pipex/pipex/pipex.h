/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:50:57 by seunan            #+#    #+#             */
/*   Updated: 2023/08/24 20:06:57 by seunan           ###   ########.fr       */
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

int		valid_path(char *path[], char *cmd);
char	**parse_path(char *envp[]);

// protected.c

int		open_outfile(char *outfile);
int		open_infile(char *infile);
void	protected_close(int fd);
void	protected_pipe(int fd[2]);
pid_t	protected_fork(void);
void	protected_dup2(int oldfd, int newfd);

// err.c

void	exit_with_err(char *err);
void	exit_with_msg(char *msg);
void	open_err(char *file);

#endif
