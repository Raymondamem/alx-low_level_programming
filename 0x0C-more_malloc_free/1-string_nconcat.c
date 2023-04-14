#include "main.h"
#include <stdlib.h>

/**
 * _strlen - count the length of a string
 * @s: the string to count
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * string_nconcat - joins two string together
 * @s1: first string
 * @s2: second string
 * @n: number of string to concatinate
 * Return: pointer to joined string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int new_len = 0;
	char *string;
	unsigned int i;
	unsigned int j;

	if (s1 != NULL)
	{
		len1 = _strlen(s1);
	}
	if (s2 != NULL)
	{
		len2 = _strlen(s2);
		if (len2 >= n)
		{
			len2 = n;
		}
	}
	new_len = len1 + len2;
	string = malloc((sizeof(char) * new_len) + 1);
	if (string == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		string[i] = s1[i];
	}
	for (j = 0; j < len2; j++, i++)
	{
		string[i] = s2[j];
	}
	string[i] = '\0';
	return (string);
}
