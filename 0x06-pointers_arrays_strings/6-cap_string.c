#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n'
		|| s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1] == '.'
		|| s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '"'
		|| s[i - 1] == '(' || s[i - 1] == ')' || s[i - 1] == '{'
		|| s[i - 1] == '}')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}

		i++;
	}

	return (s);
}
