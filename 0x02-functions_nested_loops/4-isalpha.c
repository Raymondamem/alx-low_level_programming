#include "main.h"

/**
 * _isalpha - checks if letter is lower case
 * @c: input character to check
 *
 * Example:
 * _isalpha('a') --> 1
 * _isalpha('2') --> 0
 *
 * Return: 1 for alphabets, else 0
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	return (0);
}
