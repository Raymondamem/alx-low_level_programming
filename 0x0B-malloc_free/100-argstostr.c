#include "main.h"
#include <stdlib.h>

/**
 * _strlen - count the length of a string
 * @s: the string to count
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * argstostr - concatinate argument option
 * @ac: Argument count
 * @av: Argument vector
 * Return: pointer to concatinated string
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, len;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0, len = 0; i < ac; i++)
	{
		len += _strlen(av[i]) + 1;
	}

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 0, k = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
		{
			str[k] = av[i][j];
		}
		str[k++] = '\n';
	}
	str[k] = '\0';
	return (str);
}
