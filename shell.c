#include "shell.h"
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Where the main function execution begins
 * @argc: The number of arguments vectors
 * @argv: The argument vectors
 * @env: The enviroment variable
 * Return: 0 for success
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char display_prompt[2] = "$ ", *buffer = NULL, *trim_buffer = NULL;
	int buffer_size = 2, getline_rvalue = 0, True = 1, status;
	pid_t p_id;

	while (True)
	{
		if (isatty(STDIN_FILENO))
			print_display(display_prompt);
		buffer = malloc(sizeof(char) * buffer_size);
		getline_rvalue = my_getline(&buffer, &buffer_size, stdin);
		trim_buffer = my_strtrim(buffer);
		if (getline_rvalue == -1)
			free(buffer), exit(0);
		if (trim_buffer != NULL && *trim_buffer == '\n')
		{
			free(buffer);
			continue;
		}
		if (*(trim_buffer + (getline_rvalue - 1)) == '\n')
			*(trim_buffer + (getline_rvalue - 1)) = '\0';
		if (my_strcmp(trim_buffer, "exit") == 0)
		{
			exit(0);
			break;
		}
		check_builtin(trim_buffer, env);
		p_id = fork();
		if (p_id == -1)
			perror("fork()"), free(buffer), exit(EXIT_FAILURE);
		if (p_id == 0)
			exec_function(trim_buffer, argv, env);
		else
			waitpid(p_id, &status, 0);

		free(buffer);
	}
	return (0);
}
