/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 07:50:57 by seunan            #+#    #+#             */
/*   Updated: 2023/08/22 00:53:32 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <sys/fcntl.h>
# define READ_END 0
# define WRITE_END 1

char	**parse_path(char *envp[]);
int		valid_path(char *path[], char *cmd);
void	exit_with_msg(char *msg);
int		protected_open(char *file, int flag);
void	protected_close(int fd);
void	protected_dup2(int oldfd, int newfd);
void	fd_to_outfile(char *av[], char *path[], int fd[2]);
void	infile_to_fd(char *av[], char *path[], int fd[2]);

#endif
