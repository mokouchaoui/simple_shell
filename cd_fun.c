#include "shell.h"
/**
 * cd_fun - entry current path
 * @path: store a string with current path
 */
void cd_fun(char *path)
{
	int file;

	file = chdir(path);
	if (file < 0)
		perror(path);
}
