#include "shell.h"
#include <stdlib.h>

/**
 * exit_shell - The function that exits the shell
 * @env: The enviromnet variable
 * @buffer: the string to check the exit status
 * Return: Nothing
 */
void exit_shell(char **env __attribute__((unused)), char *buffer)
{
	char *check_exit = "exit", *delim = " \n\t";
	char *check_status = "exit ";
	size_t n = 4;
	int pad_string = 1, arg_count = 0, i = 0;
	char *hold_token = NULL, *token_copy, **args = NULL;

	token_copy = malloc(my_strlen(buffer) + pad_string);
	if (token_copy == NULL)
	{
		perror("malloc");
		exit(0);
	}
	if (my_strcmp(buffer, check_exit) == 0)
	{
		free(buffer);
		exit(2);
	}
	else if (my_strncmp(buffer, check_status, n) == 0)
	{
		my_strcpy(token_copy, buffer);
		hold_token = my_strtok(buffer, delim);
		while (hold_token)
			arg_count++, hold_token = my_strtok(NULL, delim);
		args = malloc((arg_count + pad_string) * sizeof(char *));
		if (args == NULL)
			perror("malloc"), exit(0);
		my_strcpy(buffer, token_copy);
		hold_token = my_strtok(buffer, delim);
		for (i = 0; i < arg_count; i++, hold_token = my_strtok(NULL, delim))
			args[i] = hold_token;
		args[arg_count] = NULL;
		exit(atoi(args[1]));
	}
	free(token_copy);
	free(args);
}
