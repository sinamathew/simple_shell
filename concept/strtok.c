#include "main.h"

int main(void)
{
	char *str = NULL;
	size_t size = 0;
	char *token;
	int i;

	while (getline(&str, &size, stdin) != -1)
	{
		token = strtok(str, " \n");
		for (i = 0; token != NULL; i++)
		{
			printf("Number %d string is '%s'\n", i + 1, token);
			token = strtok(NULL, " \n");
		}
	}

	free(str);
	fprintf(stderr, "Error\n");
	return (1);
}
