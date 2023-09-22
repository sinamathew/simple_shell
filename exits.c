#include "shell.h"

/**
 * custom_exit - exits the shell
 * By: Noble && Sina
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info->argv[0] != "exit"
 */
int custom_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = custom_atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			custom_error(info, "Illegal number: ");
			custom_eputs(info->argv[1]);
			custom_eputchar('\n');
			return (1);
		}
		info->err_num = custom_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
