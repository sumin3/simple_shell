#include "holberton.h"
/**
 * signalhandler - handles the ctrl-c key to keep looping
 * 
 */
void signalhandler()
{
	write(STDOUT_FILENO, "\n\r$> ", 5);
}
/**
 * _strcmp - compares 2 strings
 * @s1: string1 to compare
 * @s2: string2 to compare
 * Return: -1,0,1 if string1 <, =, > string2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	while (*(s1 + i) != 0 && *(s2 + i) != 0 && diff == 0)
	{
	diff = (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (diff != 0)
	{
		return (diff);
	}
	else
	{
		if (*(s1 + i) == 0 && *(s2 + i) == 0)
			return (0);
		else
			return (*(s1 + i) - *(s2 + i));
	}
}
/**
 * _strdup - duplicates a string
 * @str: string to duplicated
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0, j;

	if (!str)
		return (NULL);
	while (*(str + i))
		i++;
	i++;
	s = malloc(sizeof(char) * i);
	if (s == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		s[j] = str[j];
	return (s);
}
/**
 * create_arg_list - takes the input buffer and creates argument list
 * @buff_tk: pointer to where the argument lis will be stored
 * @buff: buffer to get argument list from
 * @delim: delimiter to use to delimit buffer
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **buff_tk, char *buff, const char *delim)
{
	int count = 0;
	char *toprint, *buffdup;

	buffdup = _strdup(buff);
	toprint = strtok(buffdup, delim);
	while (toprint)
	{
		toprint = strtok(NULL, delim);
		count++;
	}
	free(buffdup);
	if (!count)
		return (NULL);
	buff_tk = (char **) malloc((count + 1) * sizeof(char *));
	toprint = strtok(buff, delim);
	count = 0;
	while (toprint)
	{
		buff_tk[count] = toprint;
		toprint = strtok(NULL, delim);
		count++;
	}
	buff_tk[count]  = NULL;
	return (buff_tk);
}
