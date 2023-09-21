#ifndef UTILS_H
#define UTILS_H


/*---MACROS---*/
#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 64

/* Prototypes */
int read_input(char *input);
char **parse_input(char *input);
void free_args(char **args);

#endif /* UTILS_H */

