#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define CMD_SIZE 1024

extern char **environ;

/**
 * struct line_cmds - entry command
 * @cmd: commds to search into list
 * @func: Second member
 */
typedef struct line_cmds
{
	char *cmd;
	void (*func)(char *arg);

} line_cmd;

int count_args(char **args);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void args_null(char **args, int height);
int _execve(char *pathname, char *const argv[], char *const envp[]);
void cd_fun(char *path);
void help_fun(char *path);
void print_sign(void);
char *_strcat(char *dest, char *src);
void ctrl_c(int x);

#endif/* _SHELL_H_ */
