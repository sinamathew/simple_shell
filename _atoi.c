#include "shell.h"

/**
 * custom_atoi - converts a string to an integer
 * @str: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int custom_atoi(char *str)
{
	int i, sign = 1, flag = 0, result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		return (-result);
	else
		return (result);
}
