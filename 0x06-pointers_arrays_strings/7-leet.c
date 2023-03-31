#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aeotlAEOTL";
	char numbers[] = "4307104310";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == letters[j])
			s[i] = numbers[j];
		}
	}

	return (s);
}
