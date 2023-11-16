#include "shell.h"

/**
 * my_getline - The function that gets the user input from stdin
 * @bufferptr: The function points to the buffer
 * @n: initial size allocation of the buffer
 * @stream_to_read: the stream to read from which is stdin
 * Return: A signed int(no of bytes read on success and -1 when unsuccessfull)
 */
ssize_t my_getline(char **bufferptr, int *n, FILE *stream_to_read)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_track, buffer_size;
	ssize_t no_bytes_read = 0;
	char *line, *create_new, c;

	if (!bufferptr || !n || !stream_to_read)
	{
		return (-1);
	}
	line = *bufferptr;
	while (1)
	{
		if (buffer_track == buffer_size)
		{
			buffer_size = read(fileno(stream_to_read), buffer, sizeof(buffer));
			if (buffer_size <= 0)
			{
				return ((line != NULL) ? (no_bytes_read > 0) ? no_bytes_read : -1 : -1);
			}
			buffer_track = 0;
		}
		if (no_bytes_read + 1 >= *n)
		{
			*n *= 2;
			create_new = realloc(line, *n);
			if (create_new == NULL)
				return (-1);
			line = create_new;
			*bufferptr = line;
		}
		c = buffer[buffer_track++];
		line[no_bytes_read++] = c;
		if (c == '\n')
		{
			line[no_bytes_read] = '\0';
			return (no_bytes_read);
		}
	}
}
