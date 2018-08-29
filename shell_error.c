#include "holberton.h"
/**
 * error_message - write error message to standard output
 * @argv: executable name
 * @input_count: number of times the loop has happened
 * @error_str: error message
 * @buff_tk: argument list
 * Return: return 1 when need to skip rest of code (continue) in main
 * always return 1
 */
int error_message(char *argv, int input_count, char *error_str, char **buff_tk)
{
	char *str_count = NULL, *m1 = NULL, *m2 = NULL, *m3 = NULL;

	str_count = num_to_str(input_count);
	m1 = _strcat(argv, ": ", str_count);
	m2 = _strcat(m1, ":", " ");
	m3 = _strcat(m2, buff_tk[0], error_str);
	write(STDERR_FILENO, m3, _strlen(m3));
	free(str_count);
	free(m1);
	free(m2);
	free(m3);
	return (1);
}
/**
 * permi - check permission
 * @buff_tk: pointer to where the argument list will be stored
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: return 0 if file exist, otherwise, return -1
 */
int permi(char **buff_tk, char *argv, int input_count, int *stat)
{
	if (access(buff_tk[0], F_OK) == 0)
	{
		*stat = 126;
		error_message(argv, input_count, ": Permission denied\n",
			      buff_tk);
		free(buff_tk);
		return (0);
	}
	else
		return (-1);
}
