#include <stdlib.h>
#include "main.h"

/**
 * _strncpy - copy string from one source to another
 * @dest: where to copy the string to
 * @src: from where to copy the string
 * @n: number of characters to copy
 * Return: point to the @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*src && n--)
		*dest++ = *src++;
	while (n-- > 0)
		*dest++ = '\0';
	return (ptr);
}
