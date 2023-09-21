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
int read_input(char *input, size_t size)
{
	char c;
	ssize_t n;
	size_t i = 0;

	while (i < size - 1)
	{
		n = read(STDIN_FILENO, &c, 1);

		if (n == -1)
			return (-1);

		else if (n == 0 || c == '\n')
			break;

		input[i++] = c;
	}

	input[i] = '\0';

	return (0);
}


/**
 * newline - look out for "\n" character
 * @str: pointer to the string
 * Return: i
 * By: Sina
 */
size_t newline(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

/**
 * null_terminate - look out for "\0" character
 * @str: pointer to string
 * Return: len
 * By: Sina
 */
size_t null_terminate(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
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
	int status, argc = 0;
	char nfound[] = "Command not found: ";
	char *args[MAX_ARGUMENTS];
	char emsg[] = "Error: execve\n";
	char *token = strtok(input, " ");

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		while (token != NULL && argc < MAX_ARGUMENTS - 1)
		{
			args[argc++] = token;
			token = strtok(NULL, " ");
		}
		args[argc] = NULL;
		if (execve(args[0], args, NULL) == -1)
		{
			write(STDERR_FILENO, emsg, sizeof(emsg) - 1);
			_exit(EXIT_FAILURE);
		}
	}

	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDERR_FILENO, nfound, sizeof(nfound) - 1);
			write(STDERR_FILENO, input, newline(input));
			write(STDERR_FILENO, "\n", 1);
		}
	}
	return (0);
}
