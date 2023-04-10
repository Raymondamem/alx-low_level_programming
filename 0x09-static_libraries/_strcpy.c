#include <stdlib.h>
#include "main.h"

/**
 * _strcpy - copy string from one source to another
 * @dest: where to copy the string to
 * @src: from where to copy the string
 * Return: point to the @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}
