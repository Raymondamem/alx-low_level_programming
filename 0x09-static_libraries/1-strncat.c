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
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
