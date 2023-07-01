#include "pipex.h"

int	main(int ac, char *av[])
{
	char	**argv1 = ft_split(av[2], ' ');
	char	**argv2 = ft_split(av[3], ' ');
	char	*argVec1[] = {argv1[0], argv1[1], NULL};
	char	*argVec2[] = {argv2[0], argv2[1], NULL};
	int		fd[2];
	int		file1 = open(av[1], O_RDONLY);
	int		file2 = open(av[4], O_WRONLY | O_CREAT, 0666);
	pid_t	pid;

	if (ac != 5)
	{
		perror("Not enough arguments");
		return (1);
	}
	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0) // child process
	{
		dup2(fd[1], 1);
		close(fd[0]); // 자식 프로세스는 파이프에서 읽지 않으므로 읽는 쪽을 닫는다.
		if (execve("/bin/ls", argVec, NULL) == -1)
	 		perror("Could not execute execve\n");
		return (1);
	}
	else // parent process
	{

	}
	return (0);
	return (0);
}
