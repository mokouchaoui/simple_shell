#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
/*
 * int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);


int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);


int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
*/

int countwords(char *str);
int num_space(char *str);
char **parse(char *input);
char *prompt(void);

int execute(char *cmd, char **args);

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _putchar(char c);
void _pstr(char *str);

char *_getenv(char *name);
char *locate(char *name);
char *join_path(char sep, char *path1, char *path2);
int file_exists(char *filepath);

#endif
