  #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>

  int main()
  {
     char	cmd[] = "/bin/ls";
	 char	*argVec[] = {"ls", "-l", NULL};
	 char	*envVec[] = {NULL};

	 printf("Start of execve call %s:\n", cmd);
	 printf("----------------------------------\n");
	 if (execve(cmd, argVec, envVec) == -1)
	 	perror("Could not execute execve\n");
	printf("Oops, something went wrong!\n");
	return (0);
  }
