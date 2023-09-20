#include "main.h"

/**
 * check - Checks for the existence of a file
 * @file: pointer to the file
 * By: Sina Mathew
 */
void check(char *file)
{
	if (access(file, F_OK) == 0)
		printf("%s Exist\n", file);
	printf("%s Does Not Exist\n", file);
}

/**
 * main - Main function
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t n = 0;
	char *token;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		if (getline(&line, &n, stdin) != -1)
		{
			token = strtok(line, " \t\n");
			if (token != NULL && strcmp(token, "_which") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token != NULL)
					check(line);
				else
					write(1, "Usage: _which filename ...\n", 27);
			}
			else
			{
				write(1, "Command not found\n", 18);
			}
		}
		else
		{
			write(1, "getline function failed\n", 24);
		}
		free(line);
	}
	return (0);
}
