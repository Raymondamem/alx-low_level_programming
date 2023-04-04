#include "main.h"

/**
 * _memset - memset function
 * @s: string to over ride
 * @b: char to over partd of @s
 * @n: number of @s string to over ride
 * Return: pointer to @s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
