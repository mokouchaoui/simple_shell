#include "shell.h"

/**
 * args_null - entry vector args
 * @args:	vector of input
 * @height: numbers of arguments
 */
void args_null(char **args, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		args[i] = NULL;
	}
}
