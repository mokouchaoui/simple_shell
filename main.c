#include "main.h"

/**
 * main - Handles the main control of
 * the shell program
 *
 * Return: 0
 */
int main(void)
{
	char *input;
	char *cmd;
	char **args;
	int code;

	do {
		input = prompt();
		args = parse(input);
		if (args == NULL)
			continue;
		cmd = locate(args[0]);
		code = execute(cmd, args);
	} while (code != -1);
	return (0);
}
