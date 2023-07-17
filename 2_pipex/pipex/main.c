#include "pipex.h"

int	main(int ac, char *av[])
{
	char	*path[6] = {"/bin/", "/sbin/", "/usr/bin/", "/usr/sbin/", "/usr/local/bin/", NULL};

	char	**cmd1 = ft_split(av[2], ' ');
	// char	**cmd2 = ft_split(av[3], ' ');

	char	*cmdVec1[] = {cmd1[0], cmd1[1], av[1], NULL};
	// char	*cmdVec2[] = {cmd2[0], cmd2[1], NULL};

	int		fd[2];

	pid_t	pid;

	int		file1 = open(av[1], O_RDONLY);
	// int		file2 = open(av[4], O_WRONLY | O_CREAT, 0666);

	if (ac != 5)
	{
		perror("arguments");
		return (1);
	}
	pipe(fd);
	pid = fork();

	int	flag = -1;
	int	i = 0;

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0) // child process
	{
		// dup2(fd[1], 1);
		close(fd[0]); // 자식 프로세스는 파이프에서 읽지 않으므로 읽는 쪽을 닫는다.
		while (flag < 0 || i < 5)
		{
			flag = execve("/bin/cat", cmdVec1, NULL);
			printf("flag: %d\n", flag);
			printf("%s\n", ft_strjoin(path[i], cmd1[0]));
			++i;
		}
	}
	else // parent process
	{

	}
	return (0);
}
