#include "holberton.h"

/**
 * _strcmp - compares 2 strings
 * @s1: string1 to compare
 * @s2: string2 to compare
 * Return: -1,0,1 if string1 <, =, > string2
 */

int _strcmp(char *s1, char *s2)
{
        int i = 0, diff = 0;

        while (*(s1 + i) != 0 && *(s2 + i) != 0 && diff == 0)
        {   
                diff = (*(s1 + i) - *(s2 + i));
                i++;
        }   
        if (diff != 0)
        {   
                return (diff);
        }   
        else
        {   
                if (*(s1 + i) == 0 && *(s2 + i) == 0)
                        return (0);
                else
                        return (*(s1 + i) - *(s2 + i));
        }   
}

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

