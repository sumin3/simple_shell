#include "holberton.h"
/**
 * num_to_str - convert integer to string
 * @n: the number that need to convert
 * Return: return the converted string
 */
char *num_to_str(size_t n)
{
	char *str = NULL;
	int len = 1, n_cp = n, i = 0, tmp;

	if (n_cp / 10 != 0)
	{
		len++;
		n_cp = n_cp / 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		_exit(1);
	str[i + len] = '\0';
	while (n >= 10)
	{
		tmp = n % 10;
		str[i + len - 1] = tmp + '0';
		len--;
		n = n / 10;
	}
	str[i] = n + '0';
	return (str);
}
/**
 * path_helper - searches the correct path of command and
 * concatenates the path with '/' and command
 * @path: the environment variable PATH
 * @buff_tk: the first argument of user input
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: return the concatenate string if found,
 * otherwise, return NULL if not found.
 */
char *path_helper(char *path, char **buff_tk, char *argv,
		size_t input_count, int *stat)
{
	char *path_cp = NULL, *concat_path = NULL;
	char **path_tk = NULL;
	int i = 0;

	if (path)
	{
		path_cp = _strdup(path);
		path_tk = create_arg_list(path_tk,
			path_cp, ":");
	}
	else
	{
		path_tk = NULL;
	}
	while (path_tk && path_tk[i] != NULL)
	{

		concat_path = _strcat(path_tk[i], "/", buff_tk[0]);
		if (access(concat_path, X_OK) == 0)
		{
			free(path_cp);
			free(path_tk);
			return (concat_path);
		}
		i++;
		free(concat_path);
	}
	free(path_cp);
	free(path_tk);
	*stat = 127;
	error_message(argv, input_count, 2, buff_tk);
	free(buff_tk);
	return (NULL);
}
/**
 * _getenv - searches for the environment string pointed to by name
 * @name: string containing the name of the requested variable.
 * @env: environment string
 * Return: returns the associated value to the string,
 * or NULL if that environment variable does not exist.
 */
char *_getenv(char *name, list_t **env)
{
	int i = 0, match = 0;
	list_t *temp = *env;

	while (temp)
	{
		for (i = 0; name[i]; i++)
		{
			if (temp->key[i] == name[i])
				match = 1;
			else
			{
				match = 0;
				break;
			}
		}
		if (match == 1)
			return (temp->val);
		temp = temp->next;
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
	if (!result)
		_exit(1);
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
