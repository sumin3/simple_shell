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
        int (*func)(char **buff_tk, char **env, char *buff);
} builtin_t;

int (*get_builtin_func(char **s))(char **buff_tk, char **env, char *buff);

/**
 * builtin_notfound - dummy function when command is not a builtin
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer
 * Return: always 2
 */
int builtin_notfound(char **buff_tk, char **env, char *buff);

/**
 * is_env - function to check if command entered is env and print env
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer information
 * Return: 1 if command is env, 0 otherwise
 */
int builtin_env(char **buff_tk, char **env, char *buff);

/**
 * check_exit - checks if argument is exit.
 * @buff_tk: pointer to string to check
 * @env: environment variables
 * @buff: buffer
 * Return: 0 if exit, 1 otherwise
 */
int builtin_exit(char **buff_tk, char **env, char *buff);

/**
 * _strcmp - compares 2 strings
 * @s1: string1 to compare
 * @s2: string2 to compare
 * Return: -1,0,1 if string1 <, =, > string2
 */
int _strcmp(char *s1, char *s2);

char *_getenv(char *name, char **env);
char *_strcat(char *dest, char *src, char *str);
char *path_helper(char *path, char *buff_tk);
int _strlen(char *s);
char* num_to_str(size_t n);
int error_message(char *argv, int input_count, char *buff_tk1, char **buff_tk);

/** check_input - checks command for newline character
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
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **buff_tk, char *buff, const char *delim);

#endif
