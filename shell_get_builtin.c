#include "holberton.h"
/**
* get_builtin - function to find builtin function
* @argv: program name
* @input_count: number of commands processed
* @env: environment
* @buff: buffer value
* @stat: exit status
* Return: integer
*
*/
int (*get_builtin(char **s))(char **buff_tk, list_t
	**env, char *buff, char *argv, size_t input_count, int *stat)
{
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{"cd", builtin_cd},
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
 * builtin_cd - change current working directory
 */
int builtin_cd(char **buff_tk, list_t **env, char *buff,
               char *argv, size_t input_count, int *stat)
{
        int check_cd, tokens = 0;
        list_t *temp = *env;
        char *add_str = NULL, *pwd = NULL;

        (void) buff;
        (void) stat;

        while (buff_tk[tokens])
                tokens++;
	pwd = _getenv("PWD", &temp);
        /* for case cd */
        if (tokens == 1)
        {
                add_str = _getenv("HOME", &temp);
		
                if ((check_cd = chdir(add_str)) == 0)
                {
			change_pwd(env, "OLDPWD", pwd); 
                        change_pwd(env, "PWD", add_str);
                }
        }
        else if(tokens > 1 && buff_tk[1][0] == '-')
        {
                if(buff_tk[1][0] == '-' && buff_tk[1][1] == '\0')
                {
                        add_str = _getenv("OLDPWD", &temp);
			if(chdir(add_str) == 0)
                        {
				change_pwd(env, "OLDPWD", pwd);
				add_str = NULL;
				add_str = getcwd(add_str, 0);
				change_pwd(env, "PWD", add_str);
			}
                }
        }
        else if(tokens > 1)
        {
                check_cd = chdir(buff_tk[1]);
                if (check_cd == 0)
                {
			add_str = getcwd(add_str, 0);
			change_pwd(env, "OLDPWD", pwd); 
                        change_pwd(env, "PWD", add_str);
			free(add_str);

                }
                else if (check_cd == -1)
                {
                        error_message(argv, input_count, 4, buff_tk);
                        free(buff_tk);
                        buff_tk = NULL;
                        return (1);
                }
        }
	free(buff_tk);
        return (1);
}
/**
* builtin_notfound - dummy function when command is not a builtin
* @buff_tk: pointer to pointer of commands entered
* @env: pointer to pointer of env
* @buff: buffer
* @argv: program name
* @input_count: number of commands processed
* @stat: exit status
* Return: always 2
*/
int builtin_notfound(char **buff_tk, list_t **env, char *buff,
char *argv, size_t input_count, int *stat)
{
	(void) buff_tk;
	(void) env;
	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;

	return (0);
}


/**
* builtin_env - function to print env
* @buff_tk: pointer to pointer of commands entered
* @env: pointer to pointer of env
* @buff: pointer to buffer
* @argv: program name
* @input_count: number of commands processed
* @stat: exit status
* Return: 1 if command is env, 0 otherwise
*/
int builtin_env(char **buff_tk, list_t **env, char *buff,
char *argv, size_t input_count, int *stat)
{
	int   tokens = 0, len = 0;
	list_t *temp = *env;
	char *tempstr;

	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;
	while (buff_tk[tokens])
		tokens++;
	if (tokens > 1)
		return (0);
	while (temp)
	{
		tempstr = _strcat(temp->key, "=", temp->val);
		len = _strlen(tempstr);
		write(STDOUT_FILENO, tempstr, len);
		write(STDOUT_FILENO, "\n", 1);
		free(tempstr);
		temp = temp->next;
	}

	free(buff_tk);
	return (1);

}
/**
* builtin_exit - checks if argument is exit.
* @buff_tk: pointer to string to check
* @env: pointer to environment values
* @buff: pointer to buffer
* @argv: program name
* @input_count: number of commands processed
* @stat: exit status
* Return: 0 if bad error message received in exit 1 otherwise
*
*/
int  builtin_exit(char **buff_tk, list_t **env, char *buff,
char *argv, size_t input_count, int *stat)
{
	int i = 0;
	unsigned long temp = 0;
	int error_num;
	int shifter = ((sizeof(long) - 1) * 8);

	if (buff_tk && buff_tk[1])
	{
		for (i = 0; buff_tk[1][i]; i++)
		{
			if (buff_tk[1][i] < '0' || buff_tk[1][i] > '9')
			{
				error_num = error_message(argv, input_count, 3, buff_tk);
				*stat = 2;
				if (error_num == 1)
				{
					free(buff_tk);
					buff_tk = NULL;
					return (1);
				}
			}
			else
			{
				temp = (temp * 10) + (buff_tk[1][i] - '0');
				if (temp > INT_MAX)
				{
					*stat = 2;
					error_num = error_message(argv, input_count, 3, buff_tk);
					if (error_num == 1)
					{
						free(buff_tk);
						buff_tk = NULL;
						return (1);
					}
				}
			}
		}
		*stat = (temp << shifter) >> shifter;
	}
	if (*stat > 255)
		*stat /= 256;
	free(buff);
	free(buff_tk);
	free_list(*env);
	fflush(NULL);
	_exit(*stat);
	return (0);
}

