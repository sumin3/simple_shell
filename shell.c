#include "holberton.h"
/**
 * main - main shell function
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	pid_t child_pid;
	int stat;
	char *buff = NULL;
	char **buff_tk = NULL;
	size_t br = 0;
	ssize_t read;
	char *path = NULL;
	
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$> ", 3);
		read = getline(&buff, &br, stdin);
		if (read == 0)
			break;
		if (read == -1)
		{
			break;
		}
		if (buff && buff[0] != '\n')
		{
			buff_tk = create_arg_list(buff_tk, buff, " \n");
			if (get_builtin_func(buff_tk)(buff_tk, env, buff))
			{

				if (access(buff_tk[0], X_OK) == -1)
				{
					path = _getenv("PATH", env);
					buff_tk[0] = path_helper(path, buff_tk[0]);
				}
				child_pid = fork();
				if (child_pid == -1)
				{
					perror(argv[0]);
				}
				if (child_pid == 0 && buff_tk[0])
				{
					if (execve(buff_tk[0], buff_tk, NULL) == -1)
					{
						perror(argv[0]);
						free(buff_tk);
						free(buff);
						break;
					}
				}
				else
				{
					wait(&stat);
					free(buff_tk[0]);
					free(buff_tk);
					free(buff);				
					buff_tk = NULL;
					buff = NULL;
					path = NULL;

				}
			}
		}
	}
	return (0);
}
