#include "shell.h"
#include "utils.h"
/**
 * read_input - Reads input from stdin.
 * By: Noble && Sina
 * @input: Pointer to the input buffer.
 *
 * Return: -1 on failure, 0 on success.
 */
int read_input(char *input)
{
	ssize_t n;
	size_t len = 0;

do {
	n = read(STDIN_FILENO, &input[len], 1);
	if (n == -1)
	{
		perror("read error");
		return (-1);
	}
	len++;
	}
while (n > 0 && input[len - 1] != '\n');

	if (len == 1 && input[0] == '\n')
	{
		return (-1);
	}
input[len - 1] = '\0';
return (0);
}

/**
 * parse_input - Parses input into arguments.
 * By: Sina & Noble
 * @input: Input string.
 *
 * Return: Array of argument strings.
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token;
	size_t bufsize = MAX_ARGUMENTS;
	size_t i = 0;

	args = (char **)malloc(bufsize * sizeof(char *));

	if (!args)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \t\r\n\a");

	while (token != NULL)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup error");
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += MAX_ARGUMENTS;
			args = (char **)realloc(args, bufsize * sizeof(char *));

			if (!args)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees memory allocated for argument array.
 * By: Noble & Sina
 * @args: Array of argument strings.
 */
void free_args(char **args)
{
size_t i;

	if (!args)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
