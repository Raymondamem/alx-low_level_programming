#include "main.h"

/**
 * _strspn - strspn function
 * @s: param 1
 * @accept: param 2
 * Return: count
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				count++;
				break;
			}
		}
		if (!*a)
		{
			break;
		}
		s++;
	}
	return (count);
}
