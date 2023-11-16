#include "shell.h"

/**
 * my_strlen - The function to check the length of the string
 * @s: The string
 * Return: The length of the string
 */
int my_strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
