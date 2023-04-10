#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to find
 * Return: pointer to beginning of the located substring, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;

	return ((*s == c) ? s : NULL);
}
