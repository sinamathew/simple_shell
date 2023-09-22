#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/* Function prototypes in shell.h */

/* Error handling functions */
void handle_error(char *message);
void command_not_found(char *command);
void execve_error(char *command);

/* Input functions */
char *read_input(void);

/* Execute functions */
int execute_command(char *command);

#endif /* SHELL_H */
