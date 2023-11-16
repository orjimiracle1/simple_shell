#include "shell.h"

/**
 * my_strtrim - the function trims the space
 * @str: the string to be trimmed
 * Return: the trimmed string
 */
char *my_strtrim(char *str)
{
	size_t length = 0, b_count = 0, stop_counting = 0;
	size_t result_index = 0, i;
	char pre_char = '\0';

	length = my_strlen(str);
	if (length == 0)
	{
		return (str);
	}
	while (my_isspace(*(str + b_count)))
	{
		b_count++;
	}
	if (b_count == length)
	{
		*(str + 0) = '\n';
		*(str + 1) = '\0';
		return (str);
	}
	stop_counting = length - 1;
	while (my_isspace(*(str + stop_counting)))
	{
		stop_counting--;
	}
	for (i = b_count; i <= stop_counting; i++)
	{
		if (my_isspace(*(str + i)) && !my_isspace(pre_char))
		{
			str[result_index++] = '\n';
		}
		else if (!my_isspace(*(str + i)) || (i > b_count && !my_isspace(pre_char)))
		{
			str[result_index++] = *(str + i);
		}
		pre_char = *(str + i);
	}
	*(str + result_index) = '\0';

	return (str);
}
