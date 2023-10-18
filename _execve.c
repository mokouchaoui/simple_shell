#include "shell.h"
/**
 * _execve - entry point
 * @pathname: command to search
 * @argv: array of command with arguents and path
 * @envp: get enviroment variables and compare
 * Return: value of n_exec if is true or false
 */
int _execve(char *pathname, char *const argv[], char *const envp[])
{
	int i, cmp, n_exec = 0;
	char path[128] = "/bin/";

	line_cmd cmds[] = {
			{"cd", cd_fun},
			{NULL, NULL}
	};
	if (_strcmp(pathname, "\n") == 0)
		return (0);
	
	n_exec = execve(pathname, argv, envp);
	if (n_exec == -1)
	{	
		n_exec = execve(_strcat(path, pathname), argv, envp);
		if (n_exec == -1)
		{
			for (i = 0; cmds[i].cmd != NULL; i++)
			{
				cmp = _strcmp(pathname, cmds[i].cmd);
				if (cmp == 0)
				{
					cmds[i].func(argv[1]);
					n_exec = 0;
					return (n_exec);
				}
				else
					n_exec = -1;
			}
		}
	}
	return (n_exec);
}
