#include "main.h"

/**
 * _strchr - strchr function
 * @s: string searching
 * @c: char to search
 * Return: NULL or pointer to s
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}
