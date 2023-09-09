#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t n;
	ssize_t read;

	read = getline(&line, &n, stdin);
	while(read != -1)
	{
		printf("$ ");
		printf("%lu", read);
	}

	free(line);
	return (0);
}
