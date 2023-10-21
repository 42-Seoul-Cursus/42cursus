/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:22:07 by seunan            #+#    #+#             */
/*   Updated: 2023/10/21 16:12:18 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_with_err(char *err_msg)
{
	printf("\033[31m");
	printf("Error: %s\n", err_msg);
	printf("\033[0m");
	exit(EXIT_FAILURE);
}
