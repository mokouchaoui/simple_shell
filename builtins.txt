#include "main.h"

/**
 * parse - This function splits the input into arrays
 * of words.
 * @input: The string to be splited.
 * Return: An array of words.
 */
char **parse(char *input)
{
	char **tokens;
	char *token, *dlim = " ";
	int space, i = 0, numofwords;

	numofwords = countwords(_strdup(input));
	if (numofwords == 0)
		return (NULL);
	space = num_space(input);
	tokens = malloc(sizeof(char *) * (space + 1));
	if (tokens == NULL)
		return (NULL);
	token = strtok(input, dlim);
	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		i++;
		token = strtok(NULL, dlim);
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * countwords - This function counts the number of word
 * @str: The string to be processed.
 * Return: The number of words.
 */
int countwords(char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str != ' ')
			count += 1;
		str += 1;
	}
	return (count);
}

/**
 * num_space - This function calculate the
 * number of space in a string.
 * @str: The string to be checked.
 * Return: The number of spaces plus 1.
 */
int num_space(char *str)
{
	int num = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			num += 1;
	}
	if (num == 0)
		num += 1;

	return (num);
}
