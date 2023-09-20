#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t n;
	ssize_t read;

	printf("$ ");
	while((read = getline(&line, &n, stdin)) != -1)
	{
		printf("%s", line);
		printf("$ ");
	}

	free(line);
	return (0);
}
