#include "shell.h"

/**
 * custom_add_history - Add a line to the history list
 * @info: Pointer to info structure
 * @line: The line to add
 */
void custom_add_history(info_t *info, char *line)
{
	history_t *new_history;
	history_t *current = info->history;

	new_history = malloc(sizeof(history_t));
	if (!new_history)
	{
		custom_error(info, "Memory allocation error\n");
		return;
	}
	new_history->line = custom_strdup(line);
	new_history->next = NULL;

	if (!current)
		info->history = new_history;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_history;
	}
}

/**
 * custom_free_history - Free the history list
 * @info: Pointer to info structure
 */
void custom_free_history(info_t *info)
{
	history_t *current = info->history;
	history_t *next;

	while (current)
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
	info->history = NULL;
}
