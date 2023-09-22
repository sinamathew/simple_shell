#include "shell.h"

/**
 * read_input - Read a line of input from stdin
 * Return: A pointer to the input string, or NULL on failure or EOF
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
