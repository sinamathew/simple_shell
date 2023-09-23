#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in.
 * @command: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtins[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - Handle execution of built-in commands.
 * @command: The command to execute.
 * @argv: The argument vector.
 * @status: The exit status.
 * @idx: The command index.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - Exit the shell.
 * @command: The command to execute (exit).
 * @argv: The argument vector.
 * @status: The exit status.
 * @idx: The command index.
 */
void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit: Illegal number:\n";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freearray2D(command);
			return;
		}
	}
	freearray2D(command);
	exit(exit_value);
}

/**
 * print_env - Print the environment variables.
 * @command: The command to execute (env).
 * @status: The exit status.
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(command);
	(*status) = 0;
}
