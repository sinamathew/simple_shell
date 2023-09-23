#include "shell.h"

/**
 * freearray2D - Frees a two-dimensional array of strings.
 * @arr: The array to free.
 */
void freearray2D(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}
