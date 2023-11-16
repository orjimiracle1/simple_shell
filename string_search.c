#include "shell.h"

/**
 * my_strchr - The function name
 * @s: The string to search
 * @c: The character to search in the string
 * Return: The address of the first locaion of the character
 */
char *my_strchr(char *s, char c)
{
	int i = 0;
	int value = 0;
	int n;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			n = i;
			value = 1;
			break;
		}
		i++;
	}
	if (value == 1)
		return (s + n);
	return (NULL);
}
