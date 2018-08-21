#include "holberton.h"
/**
 * error_message - write error message to standard output
 * Return: return 1 when need to skip rest of code (continue) in main
 * return 0 when do not need to skip
 */
int error_message(char *argv, int input_count, char *buff_tk1, char **buff_tk)
{
	char *str_count = NULL;

	/* error message that all different cases need to write */
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, ": ", 2);
	
	str_count = num_to_str(input_count);
	
	write(STDOUT_FILENO, str_count, _strlen(str_count));
	write(STDOUT_FILENO, ": ", 2);
	
	free(str_count);
	/* for case command not found */
	if (buff_tk[0] == NULL)
	{
		write(STDOUT_FILENO, buff_tk1, _strlen(buff_tk1));
		write(STDOUT_FILENO, ": not found\n", 12);
		return (1);
	}
	/* for case exit with a number that is greater than INT_MAX */
	else if (buff_tk[0][0] == 'e' && buff_tk[0][1] == 'x' && buff_tk[0][2] == 'i'
		 && buff_tk[0][3] == 't')
	{
		write(STDOUT_FILENO, buff_tk[0], _strlen(buff_tk[0]));
		write(STDOUT_FILENO, ": Illegal number: ", 18);
		write(STDOUT_FILENO, buff_tk[1], _strlen(buff_tk[1]));
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	return (0);
} 
