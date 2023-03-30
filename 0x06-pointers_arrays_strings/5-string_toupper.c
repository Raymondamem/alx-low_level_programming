#include "main.h"

/**
 * string_toupper - converts string to upper case
 * @s: string to convert
 * Return: pointer to @s
 */
char *string_toupper(char *s)
{
	char *p = s;

	while (*p)
	{
		if (*p >= 97 && *p <= 122)
		{
			*p -= 32;
		}
		p++;
	}
	return (s);
}
