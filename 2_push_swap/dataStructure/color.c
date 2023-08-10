#include <stdio.h>

int	main(void)
{
	for (int i = 0; i < 8; ++i)
		printf("\033[3%dm %c", i, 'a' + i);
	printf("\033[0m e");
	printf("\033[30m e\n");

	for(int i=0; i<8; i++)
        printf("\x1b[3%dm number 3%d = text color test \x1b[0m  \n",i,i);
    printf("\n");
    for(int i=0; i<8; i++)
        printf("\x1b[4%dm number 4%d = background color test \x1b[0m  \n",i,i);
	return (0);
}
