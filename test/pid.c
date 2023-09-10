#include "main.h"

int main(void)
{
	pid_t pid;

	pid = getppid();
	printf("The present parent process ID is: %d\n", pid);

	return (0);
}
