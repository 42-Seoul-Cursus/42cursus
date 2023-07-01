#include "pipex.h"

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;

	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	return (0);
}
