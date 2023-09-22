#include "shell.h"

/**
 * handle_error - Prints an error message to stderr
 * @message: The error message to print
 */
void handle_error(char *message)
{
	write(STDERR_FILENO, message, strlen(message));
}

/**
 * command_not_found - Prints a "command not found" error message
 * @command: The command that was not found
 */
void command_not_found(char *command)
{
	write(STDERR_FILENO, "Command not found: ", 19);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * execve_error - Prints an "execve" error message
 * @command: The command that failed to execute
 */
void execve_error(char *command)
{
	write(STDERR_FILENO, "Error executing  ", 15);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, "\n", 1);
}
