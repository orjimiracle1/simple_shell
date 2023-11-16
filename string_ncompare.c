#include "shell.h"

/**
 * my_strncmp - the function that compares the string str1 and str2
 * my n number of bytes
 * @str1: The first string
 * @str2: The second
 * @n: the number of bytes to compare the string str1 and str2
 * Return: 0(if str1 and str2 are equal) -ve(if str1 is less that
 * str2) +ve(if str1 is greater than str2)
 */
int my_strncmp(char *str1, char *str2, size_t n)
{
	if (n <= 0)
		return (-1);
	while (n > 0 && *str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
