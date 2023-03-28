#include "main.h"

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 * Return: void
 */
void rev_string(char *s)
{
	int i;
	int j;
	char temp;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	i--;
	for (j = 0; j < i; j++)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i--;
	}
}
