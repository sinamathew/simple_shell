#include "shell.h"
#include "utils.h"

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * execute_command - Execute a shell command.
 * @input: The command to execute.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *input)
{
	pid_t pid;
	char **args = parse_input(input);

	if (args == NULL)
	return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_args(args);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			free_args(args);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			free_args(args);
			return (-1);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
		}
		free_args(args);
	}
	return (0);
}
