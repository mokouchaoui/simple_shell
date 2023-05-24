#include "main.h"

/*
 * void sigint_handler(int sig)
{
	(void) sig;

	signal(SIGINT, sigint_handler);
}
*/

/**
 * execute - This function creates processes an execute
 * system calls in each process
 * @cmd: The command to be executed.
 * @args: The parameters of the command.
 * Return: 0 success and -1 if it fails.
 */
int execute(char *cmd, char **args)
{
	pid_t child;
	int out = 0;

	child = fork();
	if (child == -1)
	{
		perror("fork error");
		out = -1;
	}
	if (child == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror("./shell");
			exit(-1);
		}
	}
	else
		wait(NULL);

	return (out);
}
