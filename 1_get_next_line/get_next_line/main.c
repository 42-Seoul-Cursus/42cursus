/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan    <seunan@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:31:33 by seunan            #+#    #+#             */
/*   Updated: 2023/04/09 20:31:33 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // O_WRONLY
#include <stdio.h>
#include <string.h>

void	leak(void)
{
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked");
}

int	main(void)
{
	char	*buff;

	int test, no_nl;
	atexit(leak);
	no_nl = open("./no_nl.txt", 0);
	buff = get_next_line(no_nl);
	printf("%s\n", buff);
	free(buff);

	test = open("./test.txt", 0);
	/* for (int i = 0; i < 9; i++)
	{
		buff = get_next_line(test);
		printf("%d : %s\n", i + 1, buff);
		free(buff);
	} */
	close(test);
	close(no_nl);
	return (0);
}

/* 1. backup에 콘텐츠가 있는지 확인한다 (A1)
A1. 콘텐츠가 있을 경우
	1. 백업의 콘텐츠에 개행 문자가 포함되어있는지 확인한다. (A2)
		A2. 개행이 있을 경우
			1. 개행 후의 문자열을 백업에 저장 후 개행까지의 문자열을 만들어서 반환한다.
2. 버퍼를 read해서 백업과 연결해준다. strjoin을 통해 buffer에 저장
3. 버퍼의 콘텐츠에 개행 문자, '\0'이 포함되어있는지 확인한다. (A3)
	A3. 개행, 널문자가 없을 경우
		1. buffer를 백업 저장하고 2로 돌아간다.
4. line에 /n, \0 전까지의
basic path : 기본적인 흐름
alternative path : if문
exception : 예외사항 */
