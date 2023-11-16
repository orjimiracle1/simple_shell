#include "shell.h"

/**
 * my_isspace - The function checks for the appearance of the following
 * characters('\n', '\t', '\r', '\v', '\f')
 * @c: The character to check for
 * Return: non-zero if found and zero if not found
 */
int my_isspace(int c)
{
	return (c == '\n' || c == '\t' || c == '\r' || c == ' ' ||
			c == '\v' || c == '\f');
}
