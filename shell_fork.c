#include "holberton.h"
/**
* exec_command - fork and execute command
* @argv: program name
* @buff_tk: tokenized buffer
* @buff_tk1: command to run
* @buff: buffer
* @check_path: return value of check_path
* @stat: exit status
*/
void exec_command(char *argv, char **buff_tk,
		char *buff_tk1, char *buff, int check_path, int *stat)
{
	pid_t child_pid;

	(void) buff;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv);
	}
	if (child_pid == 0)
	{
		if (check_path == 0)
			buff_tk1 = buff_tk[0];
		if (execve(buff_tk1, buff_tk, NULL) == -1)
		{
			perror(argv);
			free(buff_tk);
			/*kill(0, SIGSTOP);*/
			/*free(buff);*/
		}
	}
	else
	{
		wait(stat);
		if (check_path == -1)
		{
			/*free(buff_tk[0]);*/
			free(buff_tk1);
			buff_tk1 = NULL;

		}
		free(buff_tk);
		buff_tk = NULL;
		/*free(buff);*/
	}
}
