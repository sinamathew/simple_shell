#include "shell.h"
/**
 * main - a simple shell
 * By: Noble & Sina
 * Return: 0
 */
int main(void)
{
	char *input;
	size_t input_size;

	while (1)
	{
		display_prompt();
		if (read_input(&input, &input_size) == -1)
		{
			write(STDERR_FILENO, "Error: read_input\n", 18);
			_exit(EXIT_FAILURE);
		}

		if (execute_command(input) == -1)
		{
			write(STDERR_FILENO, "Error: shell\n", 13);
		}
	}
	free(input);
	return (0);
}

