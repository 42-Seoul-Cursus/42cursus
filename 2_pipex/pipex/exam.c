  #include <sys/types.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	size_t	i;
	size_t	j;

	answer = calloc(sizeof(char), (strlen(s1) + strlen(s2) + 1));
	if (!answer)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		answer[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		answer[i++] = s2[j++];
	return (answer);
}

  int main(int ac, char *av[])
  {
	(void) ac;
	char	*cmd = ft_strjoin("/bin/", av[2]);
	char	*argVec[] = {av[2], av[3], NULL};
	//  char	*envVec[] = {NULL};

	 printf("----------------------------------\n");
	 if (execve(cmd, argVec, NULL) == -1)
	 	perror("Could not execute execve\n");
	printf("Oops, something went wrong!\n");
	return (0);
  }
