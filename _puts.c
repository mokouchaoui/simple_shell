#include "shell.h"

/**
 * _puts - printf a string
 * @str: entry string
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
