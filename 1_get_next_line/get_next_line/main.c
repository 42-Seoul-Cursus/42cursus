#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // O_WRONLY

void	leak(void)
{
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked");
}

int main(void)
{
	atexit(leak);
	char *buff;
	int fd = open("./test.txt", 0);

	for (int i = 0; i < 9; i++)
	{
		buff = get_next_line(fd);
		printf("%d : %s\n", i + 1, buff);
		free(buff);
	}

	close(fd);
	return 0;
}
