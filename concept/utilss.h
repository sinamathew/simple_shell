#include "shell.h"

/**
 * display_prompt - prints out "$ "
 * By: Noble
 * Description: displays a shell prompt which is represented by a "$"
 */
void display_prompt(void) 
{
	char prompt[] = "$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * read_input - reads inputs from stdin
 * By: Noble && Sina
 * @input: pointer to a pointer to the input
 * @size: pointer to allocated memory for input
 * Return: -1 if fail, and 0 on success
 */
int read_input(char **input, size_t *size) 
{
	char *line = NULL;
	ssize_t n;
	*size = 0;
	do 
	{
		n = read(STDIN_FILENO, &line[*size], 1);
		if (n == -1)
		{
			free(line);
			return (-1);
		}
		(*size)++;
	} 
	while (n > 0 && line[*size - 1] != '\n');

	if (*size == 1 && line[0] == '\n') 
	{
		free(line);
		return (-1);
	}
	line[*size - 1] = '\0';
	*input = line;
	return (0);
}

/**
 * lookup_command_path - looks up the full path of a command
 * By: Noble
 * @command: the command to look up
 * Return: the full path if found, or NULL if not found
 */
char *lookup_command_path(const char *command) 
{
	const char *standard_locations[] = {"/bin", "/usr/bin", NULL};
	int i;
	for ( i = 0; standard_locations[i] != NULL; i++)
	{
		char full_path[256];
		snprintf(full_path, sizeof(full_path), "%s/%s", standard_locations[i], command);
			if (access(full_path, F_OK | X_OK) == 0)
			{
				return strdup(full_path);
			}
	}
	return NULL;
}	

/**
 * execute_command - execute command taken from input
 * By: Noble && Sina
 * @input: pointer to the command
 * Return: 0 on success and -1 on error
 */
int execute_command(char *input)
{
	pid_t pid = fork();
	int status;
	char not_found[] = "Command not found: ";
	char new_line[] = "\n";
	char error_msg[] = "Error: execve\n";
	char *full_path = lookup_command_path(input);
	char *args[2];
	args[0] = full_path;
	args[1] = NULL;

    if (pid == -1) {
        write(STDERR_FILENO, "Error: fork\n", 12);
        return -1;
    }

    if (pid == 0)
    {
	    if (full_path == NULL)
	    {
		    write(STDERR_FILENO, not_found, sizeof(not_found) - 1);
		    write(STDERR_FILENO, input, strlen(input));
		    write(STDERR_FILENO, new_line, sizeof(new_line) - 1);
		    _exit(EXIT_FAILURE);
	    }
	    if (execve(full_path, args, NULL) == -1)
	    {
		    write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		    _exit(EXIT_FAILURE);
	    }
    }
    else
    {
	    waitpid(pid, &status, 0);
	    if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	    {
		    write(STDERR_FILENO, not_found, sizeof(not_found) - 1);
		    write(STDERR_FILENO, input, strlen(input));
		    write(STDERR_FILENO, new_line, sizeof(new_line) - 1);
	    }
    }
    return 0;
}

