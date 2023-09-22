#include "shell.h"

/**
 * custom_getinfo - Initializes an info_t structure with default values
 * By: Noble && Sina
 * @info: Pointer to the info_t structure to initialize
 * @av: The argument vector
 *
 * Return: No return value
 */
void custom_getinfo(info_t *info, char **av)
{
	if (!info)
		return;

	info->av = av;
	info->alias_list = NULL;
	info->history_list = NULL;
	info->line = NULL;
	info->env = NULL;
	info->readfd = STDIN_FILENO;
	info->history_count = 0;
	info->alias_count = 0;
	info->status = 0;
	info->err_num = 0;
	info->cmds = NULL;
}
