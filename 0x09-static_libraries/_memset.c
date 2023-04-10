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
	char *ptr = s;

	while (n--)
		*s++ = b;
	return (ptr);
}
