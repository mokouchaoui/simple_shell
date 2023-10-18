#include "shell.h"

/**
 * _strcpy - copy a string and remove \n character
 * @dest:	new string
 * @src:	old string
 * Return: new string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i, n = _strlen(src);

	for (i = 0; i < n; i++)
		if (src[i] != '\n')
			dest[i] = src[i];
		else
			dest[i] = '\0';
	return (dest);
}
