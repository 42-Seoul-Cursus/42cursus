#include "pipex.h"

int	main(int ac, char *av[])
{
	if (ac != 5)
	{
		perror("Not enough arguments");
		exit(0);
	}
	char	*cmd = ft_strjoin("/bin/", av[2]);
	char	*argVec[] = {av[2], av[3], NULL};
	//  char	*envVec[] = {NULL};

	 printf("----------------------------------\n");
	 if (execve(cmd, argVec, NULL) == -1)
	 	perror("Could not execute execve\n");
	printf("Oops, something went wrong!\n");
	return (0);
	return (0);
}
