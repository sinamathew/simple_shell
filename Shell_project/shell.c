#include "shell.h"

int main()
{
	char input[MAX_INPUT_SIZE];
	while (1)
	{
	
	display_prompt();
	if (read_input(input, sizeof(input)) == -1)
	{
		perror("read_input");
		exit(EXIT_FAILURE);
	}

	input[strcspn(input, "\n")] = '\0';

	if (execute_command(input) == -1)
	{
		perror("./shell");
	}
	}
	return 0;
}

