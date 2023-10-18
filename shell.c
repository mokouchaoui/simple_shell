#include "shell.h"

int main(void)
{
/* PATH */
	pid_t pid;
/* getline,iterator,execve and wait */
	int gl = 0, i = 0, count = 0, _exec = 0; 
	char *buf = NULL, *line_cmd = NULL; /* buffer and command line */
	size_t size = 1024;
/* strtok */
	char *cmd, *argv[CMD_SIZE];
	const char s[2] = " "; 
/* allocate for clean command of \n */
	line_cmd = (char *) malloc(CMD_SIZE * sizeof(char));
	if (line_cmd == NULL)
		exit(-1);

			
	while (1)
	{
		if(pid == 1)
		{	
			perror("Error ");
			exit(0);
		}
		signal(SIGINT, ctrl_c);
		print_sign();
		
		if ((gl = getline(&buf, &size, stdin)) == EOF)
		{
			free(line_cmd);
			free(buf);
			_puts("\n");
			exit(0);	
		}
		if(gl == -1)
			exit(-1);

		if (_strcmp(buf, "\n") != 0)
		{
			_strcpy(line_cmd, buf);
			cmd = strtok(line_cmd, s);
		}
		else
			cmd = strtok(buf, s);
	
		for(i = 0; cmd != NULL; i++)
		{	
			argv[i] = cmd;
			cmd = strtok(NULL, s);
		} 
		count = i;
		if ((_strcmp(argv[0],"exit")) == 0)
		{
			free(line_cmd);
			free(buf);
			exit(0);
		}	
		pid = fork();
		if(pid == 0)
		{
			_exec = _execve(argv[0], argv, environ);
			if (_exec == -1)
			{
				_puts(argv[0]);
				_puts(": command not found.\n");
			}
		}
		else
		{				
			wait(NULL);
		}	
		args_null(argv, count);
	}
	return (0);
}
