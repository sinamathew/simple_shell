#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdarg.h>
#include <dirent.h>

/* Macros */
#define BUF_SIZE 1024
#define BUFSIZE 1024
#define DELIM " \t\n\r"
#define BUF_FLUSH 0

/* Structs and Typedefs */
/**
 * struct info_s - Struct to hold shell information
 * @argv: Array of arguments
 * @argv_count: Number of arguments
 * @buffer: Command buffer
 * @env_list: List of environment variables
 * @history: Command history
 * @status: Exit status
 * @readfd: Read file descriptor
 */
typedef struct info_s
{
	char **argv;
	size_t argv_count;
	char buffer[BUF_SIZE];
	char **env_list;
	char *history;
	int status;
	int readfd;
} info_t;

/* Initialization macros */
#define INFO_INIT {NULL, 0, {0}, NULL, NULL, 0, -1}

/* Global variables */
extern char **environ;

/* Function prototypes */
void print_list(list_t *h);
void hsh(info_t *info, char **av);
void populate_env_list(info_t *info);
void read_history(info_t *info);
void custom_eputs(char *str);
void custom_eputchar(char c);
int custom_puts(char *str);
void custom_perror(info_t *info, char *message);
void custom_error(info_t *info, char *message);
int custom_strncmp(const char *s1, const char *s2, size_t n);
int custom_strcmp(const char *s1, const char *s2);
char *custom_strcpy(char *dest, const char *src);
char *custom_strdup(const char *s);
size_t custom_strlen(const char *s);
char *custom_strcat(char *dest, const char *src);
char *custom_strchr(const char *s, int c);
char *custom_strtok(char *str, const char *delim);
char *custom_getenv(info_t *info, const char *name);
int custom_setenv(info_t *info, const char *name, const char *value);
int custom_unsetenv(info_t *info, const char *name);
char *custom_getcwd(char *buf, size_t size);
int custom_chdir(const char *path);

#endif /* SHELL_H */
