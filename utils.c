#include "shell.h"

/**
 * display_prompt - prints out "$ "
 * By: Noble
 * Description: displays a shell prompt which is represented by a "$"
 */
void display_prompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}


/**
 * read_input - reads inputs from stdin
 * By: Noble && Sina
 * @input: pointer to a pointer to the input
 * @size: pointer to allocated memory for input
 * Return: -1 if fail, and 0 on success
 */
int read_input(char **input, size_t *size)
{
	char *line = NULL;
	ssize_t n;
	*size = 0;

	do {
		n = read(STDIN_FILENO, &line[*size], 1);

		if (n == -1)
		{
			free(line);
			return (-1);
		}

		(*size)++;
	} while (n > 0 && line[*size - 1] != '\n');

	if (*size == 1 && line[0] == '\n')
	{
		free(line);
		return (-1);
	}

	line[*size - 1] = '\0';
	*input = line;

	return (0);
}


/**
 * execute_command - execute command taking from input
 * @input: pointer to the command
 * Return: 0 on success and -1 on error
 * By: Noble && Sina
 */
int execute_command(char *input)
{
	pid_t pid = fork();
	int status;
	char not_found[] = "Command not found: ";
	char new_line[] = "\n";
	char *args[2];
	char error_msg[] = "Error: execve\n";
	args[0] = input;
	args[1] = NULL;

	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: fork\n", 12);
		return (-1);
	}

	if (pid == 0 && execve(input, args, NULL) == -1)
	{
		write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		_exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDERR_FILENO, not_found, sizeof(not_found) - 1);
			write(STDERR_FILENO, input, sizeof(input) - 1);
			write(STDERR_FILENO, new_line, sizeof(new_line) - 1);
		}
	}
	return (0);
}
