#include "main.h"

/**
 * _strstr - find occurence
 * @haystack: the haystack
 * @needle: the needle
 * Return: NULL or pointer
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (!*n)
		{
			return (haystack);
		}
		haystack++;
	}
	return (0);
}
