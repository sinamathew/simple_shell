#include "shell.h"

/**
 * execute_command - Execute command taken from input
 * By: Noble && Sina
 * @command: Pointer to the command
 * Return: 0 on success and -1 on error
 */
int execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		return (-1);
	}
	if (child_pid == 0)
	{
		char *argv[2];
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, NULL) == -1)
		{
			execve_error(command);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}
