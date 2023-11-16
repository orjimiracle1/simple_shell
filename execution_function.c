#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * exec_function - the function that executes other function using execve
 * @buffer: The arguments of the function
 * @argv: The vector argument
 * @env: The environment variable
 * Return: the function returns Nothing
 */
void exec_function(char *buffer, char **argv, char **env)
{
	char *validate_str = "/bin/", *delim = " \t\n";
	char *new_string, *token, **args;
	int arg_count = 0, size_vs = 4, pad_string = 1, i;

	new_string = malloc(my_strlen(validate_str) + my_strlen(buffer) + pad_string);
	if (new_string == NULL)
		perror("malloc") /*, exit(EXIT_FAILURE)*/;

	if (my_strncmp(validate_str, buffer, size_vs) != 0)
	{
		my_strcpy(new_string, validate_str);
		my_strcat(new_string, buffer);
	}
	else
	{
		my_strcpy(new_string, buffer);
	}
	token = my_strtok(buffer, delim);
	while (token)
		arg_count++, token = my_strtok(NULL, delim);

	args = malloc((arg_count + pad_string) * sizeof(char *));
	if (args == NULL)
		perror("malloc") /*, exit(EXIT_FAILURE)*/;

	my_strcpy(buffer, new_string);
	token = my_strtok(buffer, delim);
	for (i = 0; i < arg_count; i++, token = my_strtok(NULL, delim))
		args[i] = token;
	args[arg_count] = NULL;
	if (access(args[0], F_OK) != -1)
	{
		if (execve(args[0], args, env) == -1)
			perror("execve"), exit(127);
	}
	else
		perror(argv[0]), exit(127);

	free(new_string);
	free(args);
}
