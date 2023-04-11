#include "main.h"

/**
 * _strpbrk - strpbrk function
 * @s: string to search from
 * @accept: string to to search
 * Return: NULL or pointer to found string
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
				return (s);
		}
		s++;
	}
	return (0);
}
