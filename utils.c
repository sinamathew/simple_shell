#include "shell.h"

/**
 * display_prompt - prints out "$ "
 * By: Noble
 * Description: displays a shell prompt which is represented by a "$"
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}


/**
 * read_input - reads inputs from stdin
 * By: Noble
 * @input: pointer to store the input
 * @size: allocated memory for input
 * Return: -1 if fail, and 0 on success
 */
int read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		return (-1);
	}
	return (0);
}


/**
 * execute_command - don't know yet
 * @input: don't know yet
 * Return: -1 or 0
 * By: Noble
 */
int execute_command(const char *input)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
		return (-1);

	else if (pid == 0)
	{
		if (execlp(input, input, NULL) == -1)
			return (-1);
	}

	else
	{
		waitpid(pid, &status, 0);
		if (status != 0)
			fprintf(stderr, "Command not found: %s\n", input);
	}
	return (0);
}
