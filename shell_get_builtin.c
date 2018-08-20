#include "holberton.h"
/**
 * get_builtin_func - function to find builtin function
 * @s: name of builtin function to look for
 * Return: integern
 */
int(*get_builtin_func(char **s))(char **stored, char **env, char *buff)
{
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, builtin_notfound}
	};
	int i = 0;

	while(builtins[i].name)
	{
		if (_strcmp(builtins[i].name, s[0]) == 0)
			return (builtins[i].func);
		i++;
	}
	return(builtins[i].func);
}

/**
 * builtin_notfound - dummy function when command is not a builtin
 * @stored: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer
 * Return: always 2
 */
int builtin_notfound(char **stored, char **env, char *buff)
{
        (void) stored;
        (void) env;
        (void) buff;

        return (2);
}


/**
 * builtin_env - function to print env
 * @stored: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * Return: 1 if command is env, 0 otherwise
 */
int builtin_env(char **stored, char **env, char *buff)
{
	int row = 0, col = 0, tokens = 0;

	(void) buff;	
	while(stored[tokens])
		tokens++;
	if (tokens > 1)
		return(0);

	while (env && env[row])
	{   
		col = 0;
		while (env[row][col])
		{   
			col++;
		}
		write (STDOUT_FILENO, env[row], col);
		write (STDOUT_FILENO, "\n", 1);
		row++;
	}   
	return (1);

}

/**
 * builtin_exit - checks if argument is exit.  
 * @stored: pointer to string to check
 * 
 */
int  builtin_exit(char **stored, char **env, char *buff)
{
	int stat = 0, i = 0;

	(void) env;

	if (stored[1])
	{
		for (i = 0; stored[1][i]; i++)
			stat = (stat * 10) + (stored[1][i] - '0');
	}
	free(stored);
	free(buff);
	fflush(NULL);
	_exit(stat);
	return (0);

}

