#ifndef MAIN_H
#define MAIN_H

/*---MACROS---*/
#define MAX_WORDS 1024



/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/*---PROTOTYPES---*/
char **splitString(const char *str, int *word_count);
void check(char *file);

/*---TYPEDEF---*/




#endif /*MAIN_H*/
