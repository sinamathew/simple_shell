#include "shell.h"
#include "utils.h"

/**
 * main - a simple shell
 * By: Noble & Sina
 * Return 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	while (1)
	{
		display_prompt();
		if (read_input(input) == -1)
		{
			write(STDERR_FILENO, "Error: read_input\n", 18);
			_exit(EXIT_FAILURE);
		}
		if (execute_command(input) == -1)
		{
			write(STDERR_FILENO, "Error: shell\n", 13);
		}
	}
	return (0);
}
