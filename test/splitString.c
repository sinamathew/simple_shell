#include "main.h"

char **splitString(const char *str, int *word_count)
{
	// Intialize variables
	char **words = NULL;
	int count = 0;
	const char *delim = " \n";
	char *copy = strdup(str);
	char *token;

	//Allocate memory for the array of word pointers
	words = malloc(MAX_WORDS * sizeof(char *));
	if (words == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	// Tokenize the string
	token = strtok(copy, delim);
	while (token != NULL)
	{
		//Allocate memory for each word and copy the token to it
		words[count] = strdup(token);
		if (words[count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, delim);
	}
	free(copy);
	*word_count = count;
	return(words);
}
