#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#define BUFFER_SIZE 1024

void print_display(char *s);
void print_string(char *s);
void exec_function(char *buffer, char **argv, char **env);
void exit_shell(char **env, char *buffer);
void print_env(char **env, char *buffer);
ssize_t my_getline(char **lineptr, int *n, FILE *stream);
char *my_strtok(char *str, char *delim);
char *my_strchr(char *s, char c);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *s);
char *my_strcat(char *dest, char *src);
int my_strncmp(char *str1, char *str2, size_t n);
char *my_strtrim(char *str);
int my_isspace(int c);
int my_strcmp(char *s1, const char *s2);
void check_builtin(char *buffer, char **env);
char *my_strdup(char *s);
extern char **environ;

/**
 * struct Shell - The struct we are using
 * shellbuiltin - The name of the struct
 * @builtin_name: The name of the builtin function
 * @builtin_fun: The function to execute the shell builtin
 */
typedef struct Shell
{
	const char *builtin_name;
	void (*builtin_fun)(char **env, char *buffer);
} shellbuiltin;

static shellbuiltin builtincommand[] __attribute__((unused)) = {
	{"exit", &exit_shell},
	{"env", &print_env},
	{NULL, NULL}};

#endif
