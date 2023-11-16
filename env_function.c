#include "shell.h"

/**
 * print_env - The program that prints the enviroment
 * @env: The enviroment variable
 * @buffer: the buffer containing the string
 * Return: Nothing
 */
void print_env(char **env, char *buffer)
{
	char **ptr_to_env = env;

	if (strcmp(buffer, "env") == 0)
	{
		print_string(*ptr_to_env);
		ptr_to_env++;
	}
}
