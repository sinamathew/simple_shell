#include "pid.h"

int main(int ac, char **av)
{
	char *line = NULL;
	size_t n = 10;
	ssize_t value;

	(void)ac;
	(void)av;

	while (1)
	{
		printf("$ ");
		value = getline(&line, &n, stdin);
		fflush(stdout);
		if (value == -1)
		{
			printf("\n");
			break;
		}

		printf("%s", line);
	}
	free(line);

	return (0);
}

