#include "shell.h"

/**
* is_delim - check if a char is one of the delimiters
*
* @c: character to be checked
* @delim: string containing the delimiters
*
* Return: 1 if true and 0 when false
*/

unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
* _strtok - extract tokens from strings
*
* @string: string passed as argument
* @delim: string containing delimiters
*
* Return: each token on each call
*/

char *_strtok(char *string, char *delim)
{
	char *tokn = string;
	static char *stringcpy;

	if (!string)
		string = stringcpy;

	if (!string)
		return (NULL);

	while (1)
	{
		if (is_delim(*string, delim))
		{
			string++;
			continue;
		}
		if (*string == '\0')
			return (NULL);

		break;
	}
	tokn = string;
	while (1)
	{
		if (*string == '\0')
		{

			stringcpy = string;
			return (tokn);
		}
		if (is_delim(*string, delim))
		{
			*string = '\0';
			stringcpy = string + 1;
			return (tokn);
		}
		string++;
	}
}
