#include "shell.h"

/**
 * shell_loop - Main loop of the shell
 * @info: The shell info struct
 */
void shell_loop(info_t *info)
{
	char *line;
	size_t len = 0;
	ssize_t read;

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (line[0] != '\n')
		{
			info->history = line;
			custom_puts(info->history);
			custom_puts("should be put into the history list\n");
		}
	}
	while (1);
	free(line);
}
