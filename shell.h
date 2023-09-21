#ifndef SHELL_H
#define SHELL_H


/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/*---MACROS---*/
#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 64


/*---PROTOTYPES---*/
void display_prompt(void);
int read_input(char *input, size_t size);
int execute_command(char *input);
size_t newline(const char *str);
size_t null_terminate(const char *str);


#endif /* SHELL_H */
