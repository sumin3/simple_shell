#include "holberton.h"

/**
 * main - main shell function
 * @argc: number of parameters
 * @argv: arguments list
 * @env: environment variables
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	pid_t child_pid;
	ssize_t read;
	size_t input_count = 0, br = 0;
	int stat, check_path = 0, check_builtin = 0, error_num = 0;
	char *path = NULL, *buff = NULL, *buff_tk1 = NULL, **buff_tk = NULL;

	while (1)
	{
		signal(SIGINT, signalhandler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$> ", 3);
		input_count++;
		read = getline(&buff, &br, stdin);
		if (read == -1)
		{
			free(buff);
			break;
		}
		if (buff && buff[0] == '\n')
			continue;
		buff_tk = create_arg_list(buff_tk, buff, " \t\n");
		if (!buff_tk)
			continue;
		check_builtin = get_builtin_func(buff_tk)(buff_tk, env, buff);
		if (check_builtin == 1)
			continue;
		if (check_builtin == 0)
		{
			error_num = error_message(argv[0], input_count, NULL, buff_tk);
			if (error_num == 1)
			{
				free(buff_tk);
				continue;
			}
		}
		check_path = access(buff_tk[0], X_OK);
		if (check_path == -1)
		{
			path = _getenv("PATH", env);
			buff_tk1 = _strdup(buff_tk[0]);
			buff_tk[0] = path_helper(path, buff_tk[0]);
		}
		if (buff_tk[0] == NULL)
		{
			error_num = error_message(argv[0], input_count, buff_tk1, buff_tk);
			if (error_num == 1)
			{
				free(buff_tk);
				free(buff_tk1);
				continue;
			}
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
		}
		if (child_pid == 0)
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
			if (check_path == -1)
			{
				free(buff_tk[0]);
				free(buff_tk1);
			}
			free(buff_tk);
			free(buff);
			buff_tk = NULL;
			buff = NULL;
			path = NULL;
		}
	}
	return (0);
}
