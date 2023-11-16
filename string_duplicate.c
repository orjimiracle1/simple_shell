#include "shell.h"

/**
 * my_strdup - Duplicates a string passed to it
 * @s: The string passed to the function to duplicate
 * Return: A pointer to the address of the duplicated string,
 * or NULL if it fails
 */
char *my_strdup(char *s)
{
	char *duplicate_s;
	size_t length, pad_string = 1;

	length = my_strlen(s) + pad_string;
	duplicate_s = malloc(sizeof(char) * length);
	if (duplicate_s == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	my_strcpy(duplicate_s, s);
	return (duplicate_s);
}
