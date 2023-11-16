#include "shell.h"

/**
 * check_builtin - Check if the command entered is a builtin command
 * @buffer: The buffer contains the command entered by the user
 * @env: The environment variables
 * Return: No return value
 */
void check_builtin(char *buffer, char **env)
{
	char *delim = " \t\n";
	char *token;
	char *token_copy;
	int t_bin;

	token_copy = my_strdup(buffer);
	if (token_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = my_strtok(token_copy, delim);
	if (token == NULL)
	{
		free(token_copy);
		return;
	}
	for (t_bin = 0; (builtincommand + t_bin)->builtin_name != NULL; t_bin++)
	{
		if (my_strcmp(token, (builtincommand + t_bin)->builtin_name) == 0)
		{
			(builtincommand + t_bin)->builtin_fun(env, buffer);
			free(token_copy);
			return;
		}
	}
	free(token_copy);
}
