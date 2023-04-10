#include "main.h"

/**
 * _strncat - concatinating string
 * @dest: where to contacatinate the string
 * @src: wehere to get the string
 * @n: number of character to concat
 * Return: pointer to @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest + _strlen(dest);

	while (*src && n--)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
