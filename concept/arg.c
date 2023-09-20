#include "main.h"

int main(int ac, char **av)
{
	int i = 0;

	(void)ac;
	while (ac)
	{
		printf("The argument is: %s\n", av[i]);
		i++;
	}


	return (0);
}
