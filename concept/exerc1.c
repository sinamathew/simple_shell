#include "main.h"

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	pid_t childPid;
	int status;
	int i;


	for (i = 0; i < 5; i++)
	{
		childPid = fork();
		if (childPid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (childPid == 0)
		{
			/* This block is executed by the child process */
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				exit(1);
			}
		}

		else
		{
			/* This block is executed bt the parent process */
			wait(&status); /* Wait for child process to complete */
		}
	}
	return (0);
}

