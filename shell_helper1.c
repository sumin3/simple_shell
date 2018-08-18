#include "holberton.h"
/**
 * check_exit - checks if argument is exit.  
 * @argv: pointer to string to check
 * 
 */
void  check_exit(char **stored, char *buff)
{
	int stat = 0, i = 0;

	if (stored[0][0] == 'e' && stored[0][1] == 'x' &&
		stored[0][2] == 'i' && stored[0][3] == 't')
	{
		if (stored[1])
		{
			for (i = 0; stored[1][i]; i++)
				stat = (stat * 10) + (stored[1][i] - '0');
		}
		free(stored);
		free(buff);
		fflush(NULL);
		_exit(stat);
	}

}
/**
 * _strdup - malloc new memory and duplicates a string
 * @str: pointer to string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
        char *s; 
        int i = 0, j;

        if (!str)
                return (NULL);
        while (*(str + i)) 
                i++;
        i++;
        s = malloc(sizeof(char) * i); 
        if (s == NULL)
                return (NULL);
        for (j = 0; j < i; j++)
                s[j] = str[j];
        return (s);
}
/**
 * create_arg_list - takes the input buffer and creates argument list
 * @stored: pointer to where the argument lis will be stored
 * @buff: buffer to get argument list from
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **stored, char *buff, const char *delim)
{
        int count = 0;
        char *toprint, *buffdup;

        buffdup = _strdup(buff);
        toprint = strtok(buffdup, delim);
        while (toprint)
        {
                toprint = strtok(NULL, delim);
                count++;
        }
        free(buffdup);
        stored = (char **) malloc((count + 1) * sizeof(char *));
        toprint = strtok(buff, delim);
        count = 0;
        while (toprint)
        {
                stored[count] = toprint;
                toprint = strtok(NULL, delim);
                count++;
        }
        stored[count]  = NULL;
        while (stored[count])
        {
                count++;
        }
        return (stored);
}

