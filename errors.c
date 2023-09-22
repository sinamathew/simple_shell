#include "shell.h"

/**
 * custom_error - Prints an error message to stderr
 * @info: Pointer to info structure
 * @message: The error message to print
 */
void custom_error(info_t *info, char *message)
{
	custom_eputs(info, message);
}

/**
 * custom_eputs - Prints a string to stderr
 * @info: Pointer to info structure
 * @str: The string to print
 */
void custom_eputs(info_t *info, char *str)
{
	ssize_t len = custom_strlen(str);

	write(STDERR_FILENO, str, len);
}

/**
 * custom_eputchar - Prints a character to stderr
 * @info: Pointer to info structure
 * @c: The character to print
 */
void custom_eputchar(info_t *info, char c)
{
	write(STDERR_FILENO, &c, 1);
}
