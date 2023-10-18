#include "shell.h"

/**
 * count_args - count quantity arguments
 * @args: entry string
 * Return: Quantity number
 */
int count_args(char **args)
{
	int j = 0;

	while (args[j])
		j++;
	return (j);
}
