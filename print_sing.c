#include "shell.h"

/**
 * print_sign - show $ symbol and path current directory
 */
void print_sign(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
