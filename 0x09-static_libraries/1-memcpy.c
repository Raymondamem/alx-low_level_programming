#include "main.h"

/**
 * _memcpy - memcpy function
 * @dest: destination
 * @src: sourcse
 * @n: number of count
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return dest;
}
