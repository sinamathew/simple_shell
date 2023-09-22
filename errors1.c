#include "shell.h"

/**
 * custom_exit_error - Prints an exit error message to stderr
 * @info: Pointer to info structure
 * @exit_code: The exit code to print
 */
void custom_exit_error(info_t *info, int exit_code)
{
	char exit_msg[BUFSIZE];

	custom_itoa(exit_code, exit_msg);
	custom_error(info, info->argv[0]);
	custom_error(info, ": ");
	custom_error(info, exit_msg);
	custom_error(info, ": Exit: Illegal number: ");
	custom_error(info, info->argv[1]);
	custom_error(info, "\n");
}

/**
 * custom_cd_error - Prints a cd error message to stderr
 * @info: Pointer to info structure
 * @dir: The directory to print
 */
void custom_cd_error(info_t *info, char *dir)
{
	custom_error(info, info->argv[0]);
	custom_error(info, ": cd: can't cd to ");
	custom_error(info, dir);
	custom_error(info, "\n");
}

/**
 * custom_help_error - Prints a help error message to stderr
 * @info: Pointer to info structure
 */
void custom_help_error(info_t *info)
{
	custom_error(info, info->argv[0]);
	custom_error(info, ": help: help call works. Function not yet implemented\n");
}
