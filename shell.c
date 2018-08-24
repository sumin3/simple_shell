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
	ssize_t read;
	size_t input_count = 0, br = 0;
	int check_path = -1;
	char *path = NULL, *buff = NULL, *buff_tk1 = NULL, **buff_tk = NULL;

	while (1)
	{
		check_path = -1;
		signal(SIGINT, signalhandler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "> ", 3);
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
		if (get_builtin_func(buff_tk)(buff_tk, env, buff,
				argv[0], input_count))
			continue;
		if (buff_tk[0][0] == '/' || buff_tk[0][0] == '.')
			check_path = access(buff_tk[0], X_OK);
		if (check_path == -1)
		{
			path = _getenv("PATH", env);
			buff_tk1 = path_helper(path, buff_tk, argv[0], input_count);
			if (buff_tk1 == NULL)
				continue;
		}
		exec_command(argv[0], buff_tk, buff_tk1, buff, check_path);
	}
	return (0);
}
