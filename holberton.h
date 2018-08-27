#ifndef __HOLBERTON_H_
#define __HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * struct builtin - Struct builtin
 *
 * @name: Name of builtin
 * @func: Function for the buildint
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **buff_tk, char **env, char *buff,
			char *argv, size_t input_count);
} builtin_t;

/**
* exec_command - fork and execute command
* @argv: program name
* @buff_tk: tokenized buffer
* @buff_tk1: command to run
* @buff: buffer
* @check_path: value of result of check_path
* @buff: buffer
*/
void exec_command(char *argv, char **buff_tk, char *buff_tk1,
		char *buff, int check_path);

/**
 * signalhandler - handles the ctrl-c to continue looping
 * @sig: signal
 */
void signalhandler(int sig);

int (*get_builtin_func(char **))(char **, char **, char *, char *, size_t);

/**
 * builtin_notfound - dummy function when command is not a builtin
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer
 * @argv: program name
 * @input_count: number of commands already processed
 * Return: always 2
 */
int builtin_notfound(char **buff_tk, char **env, char *buff,
		char *argv, size_t input_count);

/**
 * is_env - function to check if command entered is env and print env
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer information
 * @argv: program name
 * @input_count: number of commands already processed
 * Return: 1 if command is env, 0 otherwise
 */
int builtin_env(char **buff_tk, char **env, char *buff,
		char *argv, size_t input_count);

/**
 * check_exit - checks if argument is exit.
 * @buff_tk: pointer to string to check
 * @env: environment variables
 * @buff: buffer
 * @argv: program name
 * @input_count: number of commands already processed
 * Return: 0 if exit, 1 otherwise
 */
int builtin_exit(char **buff_tk, char **env, char *buff,
		char *argv, size_t input_count);

/**
 * _strcmp - compares 2 strings
 * @s1: string1 to compare
 * @s2: string2 to compare
 * Return: -1,0,1 if string1 <, =, > string2
 */
int _strcmp(char *s1, char *s2);

char *_getenv(char *name, char **env);
char *_strcat(char *dest, char *src, char *str);
char *path_helper(char *path, char **buff_tk, char *argv, size_t input_count);
int _strlen(char *s);
char *num_to_str(size_t n);
int error_message(char *argv, int input_count, int error_num, char **buff_tk);
int permi(char **buff_tk, char *argv, int input_count);
/**
 * check_input - checks command for newline character
 * @buff: input string to check for newline
 * Return: 1 if found, 0 otherwise
 * Description: checks the input for newline character
 * if newline character is found then remove newline and
 * proceed as normal.  otherwise return 0 to stop normal
 * processing because CTRL-D with text is fond so need to
 * handle differently
 */
int check_input(char *buff);

/**
 * _strdup - malloc new memory and duplicates a string
 * @str: pointer to string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(char *str);

/**
 * create_arg_list - takes the input buffer and creates argument list
 * @buff_tk: pointer to where the argument lis will be stored
 * @buff: buffer to get argument list from
 * @delim: delimiter character(s) to use
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **buff_tk, char *buff, const char *delim);

#endif
