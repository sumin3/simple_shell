#include "holberton.h"
/**
 * path_helper - searches the correct path of command and 
 * concatenates the path with '/' and command
 * @path: the environment variable PATH
 * @command: the first argument of user input
 * Return: return the concatenate string if found, 
 * otherwise, return NULL if not found.
 */
char *path_helper(char *path, char *command)
{
	char *path_cp = NULL, *concat_path = NULL;
	char **path_tk = NULL;
	int i = 0;

	path_cp = _strdup(path);
	path_tk = create_arg_list(path_tk,
				  path_cp, ":");
	while (path_tk[i] != NULL)
	{

		concat_path = _strcat(path_tk[i], "/", command);
		if (access(concat_path, X_OK) == 0)
		{
			free(path_cp);
			free(path_tk);
			return (concat_path);
		}
		i++;
	}
	free(path_cp);
	free(path_tk);
	write(1, command, _strlen(command));
	write(1, ": command not found\n", 20);
	return (NULL);
}
/**
 * _getenv - searches for the environment string pointed to by name
 * @name: string containing the name of the requested variable.
 * @env: environment string
 * Return: returns the associated value to the string,
 * or NULL if that environment variable does not exist.
 */
char *_getenv(char *name, char **env)
{
	int match = 0;
	int i = 0, j = 0;

	while (env[i] != NULL)
	{
		for (j = 0; j < _strlen(name); j++)
		{
			if (env[i][j] == name[j])
				match = 1;
			else
			{
				match = 0;
				break;
			}
		}
		if (match == 1)
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}
/**
 * _strcat - concatenates three strings.
 * @dest: the string need to concatenated
 * @src: the string need to concatenated
 * @str: the string need to concatenated
 * Return: return a pointer to the resultring string result
 */
char *_strcat(char *dest, char *src, char *str)
{
	int total_len = 0;
	int i = 0, l = 0, m = 0, n = 0;
	char *result = NULL;

	if (!dest || !src || !str)
		return (NULL);
	total_len = _strlen(dest) + _strlen(src) + _strlen(str);
	result = malloc(sizeof(char) * (total_len + 1));
	for (i = 0; i < total_len; i++)
	{
		if (dest[l] != '\0')
		{
			result[i] = dest[l];
			l++;
		}
		else if (dest[l] == '\0' && src[m] != '\0')
		{
			result[i] = src[m];
			m++;
		}
		else if (src[m] == '\0' && str[n] != '\0')
		{
			result[i] = str[n];
			n++;
		}
	}
	result[i] = '\0';
	return (result);
}
/**
 * _strlen - return the length of a string
 * @s:the string that need to find the length
 * Return: return the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}
