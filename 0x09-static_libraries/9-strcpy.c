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
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
