#include "shell.h"

/**
 * _putchar - write a character to standard output.
 *
 * @c: input character
 *
 * Return: number of byte written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));

}


/**
* print_s - print strings to standard output
*
* @str: input string
*
* Return: number of byte written
*/
int print_s(char *str)
{
	int i = 0, byt_cnt;

	while (str[i])
	{
		byt_cnt +=  _putchar(str[i]);
		i++;

	}

	return (byt_cnt);
}
