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
	return ((_islower(c)) || (c >= 'A' && c <= 'Z'));
}
