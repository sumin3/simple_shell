#include "holberton.h"
/**
 * error_message - write error message to standard output
 * @argv: executable name
 * @input_count: number of times the loop has happened
 * @error: error number
 * @buff_tk: argument list
 * Return: return 1 when need to skip rest of code (continue) in main
 * return 0 when do not need to skip
 */
int error_message(char *argv, int input_count, int error, char **buff_tk)
{
	char *str_count = NULL;

	/* error message that all different cases need to write */
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	str_count = num_to_str(input_count);
	write(STDERR_FILENO, str_count, _strlen(str_count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buff_tk[0], _strlen(buff_tk[0]));
	free(str_count);
	if (error == 1)
	{
		write(STDERR_FILENO, ": Permission denied\n", 20);
		return (1);
	}
	/* for case command not found */
	else if (error == 2)
	{
		write(STDERR_FILENO, ": not found\n", 12);
		return (1);
	}
	/* for case exit with a number that is greater than INT_MAX */
	else if (error == 3)
	{
		write(STDERR_FILENO, ": Illegal number: ", 18);
		write(STDERR_FILENO, buff_tk[1], _strlen(buff_tk[1]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	return (0);
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
		error_message(argv, input_count, 1, buff_tk);
		free(buff_tk);
		return (0);
	}
	else
		return (-1);
}
