#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void display_prompt();
int read_input(char *input, size_t size);
int execute_command(const char *input);

#endif /* SHELL_H */

