#include "shell.h"

/**
 * my_strcat - The function that cat src to dest
 * @dest: The destination of the string
 * @src: The source of the string to catenate
 * Return: An address of the string
 */
char *my_strcat(char *dest, char *src)
{
	int i = 0, j = 0, k;

	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
		j++;
	for (k = 0; k <= j; k++)
	{
		*(dest + (i + k)) = *(src + k);
	}
	return (dest);
}
