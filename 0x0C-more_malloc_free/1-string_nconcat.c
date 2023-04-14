#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concat two string together,
 * @s1: string (1),
 * @s2: string (2)
 * @n: n bytes of @s2
 * return: returns @s1 + n bytes of @s2
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i;

	if (s1 != NULL)
		len1 = strlen(s1);
	if (s2 != NULL)
		len2 = strlen(s2);

	if (n >= len2)
		n = len2;

	ew_str = malloc(sizeof(char) * (len1 + n + 1));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	for (i = 0; i < n; i++)
		new_str[len1 + i] = s2[i];

	new_str[len1 + n] = '\0';

	return (new_str);
}
