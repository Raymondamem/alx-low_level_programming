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
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
