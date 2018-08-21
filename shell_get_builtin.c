#include "holberton.h"
/**
 * get_builtin_func - function to find builtin function
 * @s: name of builtin function to look for
 * Return: integern
 */
int(*get_builtin_func(char **s))(char **buff_tk, char **env, char *buff)
{
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, builtin_notfound}
	};
	int i = 0;

	while (builtins[i].name)
	{
		if (_strcmp(builtins[i].name, s[0]) == 0)
			return (builtins[i].func);
		i++;
	}
	return (builtins[i].func);
}

/**
 * builtin_notfound - dummy function when command is not a builtin
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer
 * Return: always 2
 */
int builtin_notfound(char **buff_tk, char **env, char *buff)
{
	(void) buff_tk;
	(void) env;
	(void) buff;

	return (0);
}


/**
 * builtin_env - function to print env
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: pointer to buffer
 * Return: 1 if command is env, 0 otherwise
 */
int builtin_env(char **buff_tk, char **env, char *buff)
{
	int row = 0, col = 0, tokens = 0;

	(void) buff;
	while (buff_tk[tokens])
		tokens++;
	if (tokens > 1)
		return (2);

	while (env && env[row])
	{
		col = 0;
		while (env[row][col])
		{
			col++;
		}
		write(STDOUT_FILENO, env[row], col);
		write(STDOUT_FILENO, "\n", 1);
		row++;
	}
	return (1);

}

/**
 * builtin_exit - checks if argument is exit.
 * @buff_tk: pointer to string to check
 * @env: pointer to environment values
 * @buff: pointer to buffer
 * Return: 0 if bad error message received in exit 1 otherwise
 *
 */
int  builtin_exit(char **buff_tk, char **env, char *buff)
{
	int stat = 0, i = 0;
	unsigned long temp = 0;
	int shifter = ((sizeof(long) - 1) * 8);

	(void) env;

	if (buff_tk[1])
	{
		for (i = 0; buff_tk[1][i]; i++)
		{
			if (buff_tk[1][i] < '0' || buff_tk[1][i] > '9')
			{
				return (0);
			}
			else
			{
				temp = (temp * 10) + (buff_tk[1][i] - '0');
				if (temp > INT_MAX)
				{
					return (0);
				}
			}
		}
		stat = (temp << shifter) >> shifter;
	}
	free(buff_tk);
	free(buff);
	fflush(NULL);
	_exit(stat);
	return (1);
}

