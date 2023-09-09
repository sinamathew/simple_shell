#include "shell.h"

void display_prompt()
{
	printf("$ ");
	fflush(stdout);
}

int read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		return -1;
	}
	return 0;
}

int execute_command(const char *input)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		return -1;
	}
	else if (pid == 0)
	{
        
	 if (execlp(input, input, NULL) == -1)
	 {
		 return -1;
	 }
	}
	else
	{
	
        int status;
        waitpid(pid, &status, 0);
	if (status != 0)
	{
		fprintf(stderr, "Command not found: %s\n", input);
	}
	}
	return 0;
}
