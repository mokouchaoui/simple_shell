#include "shell.h"
/**
 * ctrl_c - function to handle ctrl+c
 * @x: parameter to operate
 * Return: its a void function
 */
void ctrl_c(int x)
{
	(void) x;
	write(1, "\n$ ", 3);
	fflush(stdout);
}
