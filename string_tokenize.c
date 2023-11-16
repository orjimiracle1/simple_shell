#include "shell.h"

/**
 * my_strtok - Tokenize a string using the delimeter passed to the function
 * @str: The string to be tokenzised
 * @delim: The delimiter to tokenize the string with
 *
 * Return: A pointer to the next token or it retuns
 * NULL if there are no more tokens
 */
char *my_strtok(char *str, char *delim)
{
	static char *end_of_last_token;
	char *start_of_token;

	if (str != NULL)
	{
		end_of_last_token = str;
	}
	else if (end_of_last_token == NULL)
	{
		return (NULL);
	}
	while (*end_of_last_token != '\0' && my_strchr(delim,
				*end_of_last_token) != NULL)
	{
		end_of_last_token++;
	}
	start_of_token = end_of_last_token;
	if (*start_of_token == '\0')
	{
		return (NULL);
	}
	while (*end_of_last_token != '\0' && my_strchr(delim,
				*end_of_last_token) == NULL)
	{
		end_of_last_token++;
	}
	if (*end_of_last_token != '\0')
	{
		*end_of_last_token = '\0';
		end_of_last_token++;
	}
	return (start_of_token);
}
