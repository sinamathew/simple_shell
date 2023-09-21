#ifndef SHELL_H
#define SHELL_H


/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/*---PROTOTYPES---*/
void display_prompt(void);
int read_input(char *input);
char **parse_input(char *input);
void free_args(char **args);
int execute_command(char *input);


#endif /* SHELL_H */
