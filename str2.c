#include "main.h"

/**
 * _strcmp - This function compares two strings
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if they are equal or any othe
 *  integer apart from zero if they are.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _getenv - Checks for an environment variable.
 * @name: The name of the environment variable.
 * Return: The environment variable an it value or NULL.
 */
char *_getenv(char *name)
{
	size_t i = 0, j = 0;
	char *env_name;

	while (env_name != NULL)
	{
		env_name = environ[i];

		while (env_name[j] == name[j] && env_name[i] != '=')
			j++;

		if (name[j] == '\0')
			return (_strdup(env_name));

		i++;
	}
	return (NULL);
}

/**
 * locate - This function locates a command.
 * @name: The name of the command to be searched.
 * Return: The path of the command or NULL.
 */
char *locate(char *name)
{
	char *path = _getenv("PATH");
	char *dir_path = NULL;
	char *file_path = NULL;

	/*PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin*/
	if (file_exists(name))
		return (_strdup(name));

	strtok(path, "=");
	dir_path = strtok(NULL, ":");
	while (dir_path)
	{
		file_path = join_path('/', dir_path, name);
		if (file_exists(file_path))
			return (file_path);

		dir_path = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * join_path - This function joins two path using
 * a seperator
 * @sep: The separator of the paths
 * @path1: The first path.
 * @path2: The second path.
 * Return: The joined path.
 */
char *join_path(char sep, char *path1, char *path2)
{
	char *file_path;
	size_t len = 0, l1, l2;

	l1 = strlen(path1);
	l2 = strlen(path2);
	len = l1 + l2 + 2; /* 1 for sep, 1 for NULL */
	file_path = malloc(sizeof(*file_path) * len);
	if (file_path == NULL)
		printf("malloc failed.");

	_strcpy(file_path, path1);
	file_path[l1] = sep;
	_strcat(file_path, path2);
	file_path[l1 + l2 + 2] = '\0';

	return (file_path);
}

/**
 * file_exists - This function checks if a file path exist.
 * @filepath: The file path to be checked.
 * Return: 1 (if it exists) or 0 if it don't.
 */
int file_exists(char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
		return (1); /* File exist */

	return (0);
}
