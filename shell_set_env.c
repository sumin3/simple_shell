#include "holberton.h"

/**
 * change_pwd - changes current working directory
 * @env_cp:  copy of the environment
 * @key: environment variable to look for
 * @add: value of environment to add
 * Return: 1 if successful -1 if not
 */
int change_pwd(list_t **env_cp, char *key, char *add)
{
	list_t *temp = *env_cp;
	int index = 0;
	char *temp_str = NULL, *temp_val = NULL, *temp_key = NULL;

	while (temp && (_strcmp(temp->key, key) != 0))
	{
		index++;
		temp = temp->next;
	}
	if (temp)
	{
		if (delete_node_at_index(env_cp, index) == -1)
		{
			return (-1);
		}
	}
	temp_str = _strcat(key, "=", add);
	temp_val = make_key_val(temp_str);
	temp_key = temp_str;
	temp = add_node_end(env_cp, temp_key, temp_val);
	return (1);

}
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
	int  tokens = 0;
	char *temp_val, *temp_key;

	(void) buff;

	while (buff_tk[tokens])
		tokens++;
	if (tokens < 3)
	{
		/* print error message and return (1) */
		*stat = 1;
		error_message(argv, input_count, ": Invalid Argument for setenv\n", buff_tk);
	}
	else
	{
		tempstr = _strcat(buff_tk[1], "=", buff_tk[2]);
		temp_val = make_key_val(tempstr);
		temp_key = tempstr;
		while (temp && _strcmp(buff_tk[1], temp->key))
			temp = temp->next;
		if (temp)
		{
			free(temp->key);
			temp->key = temp_key;
			temp->val = temp_val;
		}
		else
		{
			*env = add_node_end(env, temp_key, temp_val);
		}
		*stat = 0;
	}
	free(buff_tk);
	return (1);

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
	while (buff_tk[tokens])
		tokens++;
	if (tokens < 2)
	{
		*stat = 1;
		error_message(argv, input_count,
			      ": Invalid Argument for unsetenv\n", buff_tk);
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
				error_message(argv, input_count,
					      ": unsetenv failed\n", buff_tk);
			}
		}
		else
		{
			*stat = 1;
			error_message(argv, input_count,
				      ": Environment Variable not found\n",
				      buff_tk);
		}
		*stat = 0;
	}
	free(buff_tk);
	return (1);

}
