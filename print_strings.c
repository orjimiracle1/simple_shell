#include "shell.h"
#include <unistd.h>

/**
 * print_string- The function prints the string passed to it to stdout
 * @s: The string to be printed
 * Return: The function returns nothing
 */
void print_string(char *s)
{
	write(STDOUT_FILENO, s, strlen(s));
}
