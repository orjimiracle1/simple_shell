#include "shell.h"

/**
 * my_strcmp - The function name that compares the two string
 * @s1: The first string
 * @s2: The second string
 * Return: An integer value
 */
int my_strcmp(char *s1, const char *s2)
{
	int i = 0, j = 0;

	while (*(s1 + i) != '\0')
		i++;
	while (*(s2 + j) != '\0')
		j++;
	if (i < j)
		return (-15);
	else if (i > j)
		return (15);
	else
		return (0);
}
