#ifndef __HOLBERTON_H_
#define __HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

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
 * @stored: pointer to where the argument lis will be stored
 * @buff: buffer to get argument list from
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **stored, char *buff);

/**
 * check_exit - checks if argument is exit.  
 * @argv: pointer to string to check
 * Return: 1 if exit, 0 otherwise
 */
void check_exit(char **stored, char *buff);
#endif
