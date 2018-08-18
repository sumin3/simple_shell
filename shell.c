#include "holberton.h"
/**
 * main - main shell function
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	pid_t child_pid;
	int stat;
	char *buff = NULL;
	char **stored = NULL;
	size_t br = 0;
	ssize_t read;


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
		if (!check_input(buff))
		{
			printf("special handling\n");
		}
		else 
		{
			if (buff && buff[0])
			{
				stored = create_arg_list(stored, buff);
				check_exit(stored, buff);

				/*if (check_exit(stored[0], stored, buff))
				  {
				  free(stored);
				  free(buff);
				  fflush(NULL);
				  _exit(stat);
				  }
				  */
				child_pid = fork();
				if (child_pid == -1)
				{
					perror(argv[0]);
				}
				if (child_pid == 0)
				{
					if (execve(stored[0], stored, NULL) == -1)
					{
						perror(argv[0]);
						free(stored);
						free(buff);
						break;
					}
				}
				else
				{
					wait(&stat);
					free(stored);
					free(buff);
					stored = NULL;
					buff = NULL;

				}
			}
		}
	}
	return (0);
}
