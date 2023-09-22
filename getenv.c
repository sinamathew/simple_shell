#include "shell.h"

/**
 * custom_getenv - retrieves the value of an environment variable
 * By:Noble && Sina
 * @info: Structure containing the environment variables
 * @name: The name of the environment variable to retrieve
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *custom_getenv(info_t *info, const char *name)
{
	int i, len = custom_strlen(name);

	if (!info->env)
		return (NULL);
	for (i = 0; info->env[i]; i++)
	{
		if (custom_strncmp(info->env[i], name, len) == 0)
		{
			return (info->env[i] + len);
		}
	}
	return (NULL);
}
