#include "shell.h"

/**
 * my_strcpy - The function name that copies the strin
 * @dest: The destination of the string
 * @src: the main string to copy from
 * Return: The address of the string
 */
char *my_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (*(src + i) != '\0')
		i++;
	for (j = 0; j <= i; j++)
	{
		*(dest + j) = *(src + j);
	}
	return (dest);
}
