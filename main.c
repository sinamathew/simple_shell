#include "shell.h"

/**
 * main - Entry point for the simple shell
 * By: Noble && Sina
 * Return: Always 0
 */
int main(void)
{
	char *command;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		command = read_input();
		if (command == NULL)
			break;
		status = execute_command(command);
		free(command);
		if (status == -1)
			handle_error("Error executing command\n");
		else if (status == 127)
			command_not_found(command);
	}
	return (0);
}
