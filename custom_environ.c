#include "shell.h"

/**
 * custom_setenv - Sets an environment variable
 * By: Noble && Sina
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable to set
 * @value: The value to set for the environment variable
 * @overwrite: Flag indicating whether to overwrite the variable if it exists
 * Return: 0 on success, -1 on failure
 */
int custom_setenv(info_t *info, const char *name, const char *value, int overwrite)
{
	int i, len, cmp;
	char *new_env_var;
	char **environ_copy = NULL;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		info->status = 2;
		custom_error(info, "Invalid argument: name");
		return (-1);
	}
	if (value == NULL)
		value = "";
	len = custom_strlen(name) + custom_strlen(value) + 2;
	for (i = 0; environ[i] != NULL; i++)
	{
		cmp = custom_strncmp(environ[i], name, custom_strlen(name));
		if (cmp == 0 && environ[i][custom_strlen(name)] == '=')
		{
			if (!overwrite)
				return (0);
			new_env_var = custom_str_concat(name, "=", value, NULL);
			if (new_env_var == NULL)
			{
				info->status = 2;
				custom_error(info, "Memory allocation error");
				return (-1);
			}
			environ[i] = new_env_var;
			return (0);
		}
	}
	environ_copy = custom_malloc((i + 2) * sizeof(char *));
	if (environ_copy == NULL)
	{
		info->status = 2;
		custom_error(info, "Memory allocation error");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
		environ_copy[i] = environ[i];

	new_env_var = custom_str_concat(name, "=", value, NULL);
	if (new_env_var == NULL)
	{
		custom_free(environ_copy);
		info->status = 2;
		custom_error(info, "Memory allocation error");
		return (-1);
	}
	environ_copy[i] = new_env_var;
	environ_copy[i + 1] = NULL;

	environ = environ_copy;
	return (0);
}

/**
 * custom_unsetenv - Unsets an environment variable
 * By: Noble && Sina
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int custom_unsetenv(info_t *info, const char *name)
{
	int i, j, len;
	char **environ_copy = NULL;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		info->status = 2;
		custom_error(info, "Invalid argument: name");
		return (-1);
	}
	for (len = 0; environ[len] != NULL; len++)
		;

	environ_copy = custom_malloc((len + 1) * sizeof(char *));
	if (environ_copy == NULL)
	{
		info->status = 2;
		custom_error(info, "Memory allocation error");
		return (-1);
	}
	for (i = 0, j = 0; environ[i] != NULL; i++)
	{
		if (custom_strncmp(environ[i], name, custom_strlen(name)) != 0 ||
				environ[i][custom_strlen(name)] != '=')
		{
			environ_copy[j] = environ[i];
			j++;
		}
	}
	environ_copy[j] = NULL;
	environ = environ_copy;
	return (0);
}

/**
 * custom_getenv - Gets the value of an environment variable
 * By: Noble && Sina
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable to retrieve
 * Return: The value of the environment variable if found, NULL otherwise
 */
char *custom_getenv(info_t *info, const char *name)
{
	int i, cmp;
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		info->status = 2;
		custom_error(info, "Invalid argument: name");
		return (NULL);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		cmp = custom_strncmp(environ[i], name, custom_strlen(name));
		if (cmp == 0 && environ[i][custom_strlen(name)] == '=')
			return (environ[i] + custom_strlen(name) + 1);
	}
	return (NULL);
}
