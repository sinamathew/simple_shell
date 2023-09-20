#ifndef SHELL_H
#define SHELL_H


/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/*---PREPROCESSORs---*/
#define MAX_INPUT_SIZE 1024


/*---PROTOTYPES---*/
void display_prompt(void);
int read_input(char *input, size_t size);
int execute_command(const char *input);


#endif /* SHELL_H */
