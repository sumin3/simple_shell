#include "holberton.h"
/**
 * builtin_setenv - sets or updates environment variable
 * @buff_tk: tokenized buffer
 * @env: linked list of environment variable
 * @buff: input buffer
 * @argv: program name
 * @input_count: number of commands executed
 * @stat: exit code
 * Return: 0 if successful 1 otherwise
 */
int builtin_setenv(char **buff_tk, list_t **env, char *buff,
		char *argv, size_t input_count, int *stat)
{
	list_t *temp = *env;
	char *tempstr;
	unsigned int index = 0;
	int  tokens = 0;
	char *temp_val, *temp_key;

	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;

	while (buff_tk[tokens])
		tokens++;
	if (tokens != 3)
	{
		/* print error message and return (1) */
		*stat = 1;
		error_message(argv, input_count, 4, buff_tk);
		return (1);
	}
	else
	{
		while (temp && _strcmp(buff_tk[1], temp->key))
		{
			index++;
			temp = temp->next;
		}
		if (temp)
		{
			if (delete_node_at_index(env, index) == -1)
				_exit(1);
		}
		tempstr = _strcat(buff_tk[1], "=", buff_tk[2]);
		temp_val = make_key_val(tempstr);
		temp_key = tempstr;
		*env = add_node(env, temp_key, temp_val);
		free(buff_tk);
		return (1);
	}

}
/**
 * builtin_unsetenv -  removes environment variable
 * @buff_tk: tokenized buffer
 * @env: linked list of environment variable
 * @buff: input buffer
 * @argv: program name
 * @input_count: number of commands executed
 * @stat: exit code
 * Return: 0 if successful 1 otherwise
 */
int builtin_unsetenv(char **buff_tk, list_t **env, char *buff,
		char *argv, size_t input_count, int *stat)
{
	list_t *temp = *env;
	unsigned int index = 0;
	int tokens = 0;

	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;

	while (buff_tk[tokens])
		tokens++;
	if (tokens != 2)
	{
		*stat = 1;
		error_message(argv, input_count, 5, buff_tk);
	}
	else
	{
		while (temp && _strcmp(buff_tk[1], temp->key))
		{
			index++;
			temp = temp->next;
		}
		if (temp)
		{
			if (delete_node_at_index(env, index) == -1)
			{
				*stat = 1;
				error_message(argv, input_count, 7, buff_tk);;
			}
		}
		else
		{
			*stat = 1;
			error_message(argv, input_count, 6, buff_tk);
		}
	}
	free(buff_tk);
	return (1);

}
