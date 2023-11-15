#include "shell.h"


/**
 * _realloc - Reallocates a memory block using malloc and free.
 *
 * @pt: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *pt, unsigned int old_size, unsigned int new_size)
{
	char *ptr_cpy, *filler;
	void *mem;
	unsigned int index;

	if (new_size == old_size)
		return (pt);

	if (pt == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && pt != NULL)
	{
		free(pt);
		return (NULL);
	}

	ptr_cpy = pt;
	mem = malloc(sizeof(*ptr_cpy) * new_size);
	if (mem == NULL)
	{
		free(pt);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_cpy++;

	free(pt);
	return (mem);
}

/**
 * assign_bufptr - Reassigns the lineptr variable for _getline.
 *
 * @bufferptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @buff_size: The size of buffer.
 */
void assign_bufptr(char **bufferptr, size_t *n, char *buffer, size_t buff_size)
{
	if (*bufferptr == NULL)
	{
		if (buff_size > 120)
			*n = buff_size;
		else
			*n = 120;
		*bufferptr = buffer;
	}
	else if (*n < buff_size)
	{
		if (buff_size > 120)
			*n = buff_size;
		else
			*n = 120;
		*bufferptr = buffer;
	}
	else
	{
		_strcpy(*bufferptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream
 *
 * @bufferptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **bufferptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_bufptr(bufferptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
