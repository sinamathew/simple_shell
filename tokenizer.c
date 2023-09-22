#include "shell.h"

/**
 * custom_strtok - custom implementation of strtok
 * @str: the string to tokenize
 * @delim: the delimiter characters
 *
 * Return: an array of pointers to the tokens
 */
char **custom_strtok(char *str, const char *delim)
{
	char *token;
	char **tokens = NULL;
	size_t token_count = 0;
	size_t tokens_size = 10;

	if (!str)
		return (NULL);

	tokens = malloc(tokens_size * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(str, delim);
	while (token)
	{
		tokens[token_count] = custom_strdup(token);
		if (!tokens[token_count])
		{
			custom_free_tokens(tokens);
			return (NULL);
		}
		token_count++;

		if (token_count >= tokens_size)
		{
			tokens_size += 10;
			tokens = custom_realloc(tokens, tokens_size * sizeof(char *));
			if (!tokens)
			{
				custom_free_tokens(tokens);
				return (NULL);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * custom_free_tokens - frees an array of token strings
 * @tokens: the array of tokens to free
 */
void custom_free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		custom_free(tokens[i]);
	}
	custom_free(tokens);
}
