#include "shell.h"

/**
 * custom_getline - Custom implementation of the getline function
 * @info: Pointer to info structure
 * Return: A pointer to the read line on success, NULL on failure or EOF
 */
char *custom_getline(info_t *info)
{
	ssize_t read_bytes;
	size_t len = 0;
	char *line = NULL;

	read_bytes = getline(&line, &len, info->readstream);
       	if (read_bytes == -1)
	{
		if (feof(info->readstream))
		{
			if (info->isatty)
				custom_putchar('\n');
			free(line);
			return (NULL);
		}
		custom_error(info, "Error reading from input\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	if (info->isatty)
		info->hist_count++;
	return (line);
}
