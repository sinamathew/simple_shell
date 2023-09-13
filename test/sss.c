#include "main.h"

int main(void)
{
	char *input = NULL;
	size_t input_len = 0;
	pid_t childPid;
	char *args[2] = {input, NULL};
	int status;

	while (1)
	{
        	/* Print a prompt, e.g., "#cisfun$ " */
        	printf("#cisfun$ ");

		/* Read user input using getline */
        	if (getline(&input, &input_len, stdin) == -1)
		{
            		perror("getline");
			break;  /* Exit the loop on error or Ctrl+C */
		}

		/* Remove the newline character from the input */
		input[strcspn(input, "\n")] = '\0';

        	/* Fork a new process */
		childPid = fork();

		if (childPid == -1)
		{
			perror("fork");
			break;  /* Exit the loop on fork error */
		}

		if (childPid == 0)
		{
			/* This block is executed by the child process */

            		/* Tokenize the input to separate the command from any arguments */

			/* Execute the command with execve */
			if (execve(input, args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* This block is executed by the parent process */

			/* Wait for the child process to complete */
			wait(&status);
		}
	}

	/* Free memory and exit */
	free(input);
	return (0);
}

