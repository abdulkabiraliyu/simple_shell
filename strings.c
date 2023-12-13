#include "shell.h"

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}


/**
 * _concat_strings - concatenate two strings together
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: concatenated string
 */
char *_concat_strings(const char *str1, const char *str2)
{

	size_t len_A = 0;
	size_t len_B = 0;
	size_t i;
	char *result;

	while (str1[len_A] != '\0')
	{
		len_A++;
	}

	while (str2[len_B] != '\0')
	{
		len_B++;
	}


	result = (char *)malloc(len_A + len_B + 1);

	if (result == NULL)
	{
		perror("Error <malloc>:");
		free(result);
		return (NULL);
	}

	for (i = 0; i < len_A; i++)
	{
		result[i] = str1[i];
	}


	for (i = 0; i < len_B; i++)
	{
		result[len_A + i] = str2[i];
	}


	result[len_A + len_B] = '\0';
	return (result);
}

/**
 * _cmpStrings - compare two strings if they are the same or not
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if not the same and 1 otherwise
 */
int _cmpStrings(const char *str1, const char *str2)
{
    
	while (*str1 != '\0' || *str2 != '\0')
	{
        	if (*str1 != *str2)
		{
            		return (1);
		}
        	str1++;
        	str2++;
    	}

    return (0); 
}
/*
 *
 *
 *
 */
char* _duplString(const char *str)
{
   int i, len = 0;
   char *dupl; 
   while (str[len] != '\0')
   {
       len++;
   }

   dupl =  (char *)malloc((len + 1) * sizeof(char));

   if (dupl == NULL)
   {
       perror("Memory allocation failed.");
       return (NULL);
   }

   for (i = 0; i <= len; i++)
   {
       dupl[i] = str[i];
   }

   return (dupl);
}
