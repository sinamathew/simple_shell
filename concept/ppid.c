#include "pid.h"

int main(void){
	pid_t ppid;

	ppid = getppid();
	printf("Parent Process Identifier is: %d\n", ppid);
	return(0);
}
