#include "shell.h"

/**
 * is_cmd - checks if a string is a valid command
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @s: string to be evaluated
 *
 * Return: 1 if s is a command, 0 otherwise
 */
int is_cmd(info_t *info, char *s)
{
	if (access(s, X_OK) == 0)
	{
		info->path = s;
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates a segment of a string
 * @s: the string to be duplicated
 * @i: the index at which to start duplication
 * @j: the index at which to stop duplication
 *
 * Return: pointer to duplicated string
 */
char *dup_chars(char *s, int i, int j)
{
	char *str;
	int k, len = j - i + 1;

	if (s == NULL)
		return (NULL);

	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);

	for (k = 0; i <= j; i++, k++)
		str[k] = s[i];

	str[k] = '\0';
	return (str);
}

/**
 * find_path - finds PATH variable and evaluates if s is in path
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @s: string to be evaluated
 * @path: path variable
 *
 * Return: pointer to matching PATH string or NULL
 */
char *find_path(info_t *info, char *s, char *path)
{
	char *dir, *tmp;
	struct stat sb;
	int len = 0;

	if (s[0] == '/')
	{
		if (stat(s, &sb) == 0)
		{
			if (S_ISREG(sb.st_mode) && sb.st_mode & S_IXUSR)
			{
				info->path = s;
				return (s);
			}
		}
		return (NULL);
	}
	while (path[len] != '\0')
	{
		dir = dup_chars(path, len, len);
		tmp = _strcat(dir, "/");
		tmp = _strcat(tmp, s);

		if (stat(tmp, &sb) == 0)
		{
			if (S_ISREG(sb.st_mode) && sb.st_mode & S_IXUSR)
			{
				free(dir);
				info->path = tmp;
				return (tmp);
			}
		}
		free(dir);
		len++;
	}
	return (NULL);
}
