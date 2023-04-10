#include "main.h"

/**
 * _strcat - concatinating string
 * @dest: where to contacatinate the string
 * @src: wehere to get the string
 * Return: pointer to @dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
