#include "main.h"

/**
 * _atoi - prints a string
 * @s: the string to print
 * Return: void
 */
int _atoi(char *s)
{
	int sign = 1;
	int res = 0;

	while (*s == ' ')
		s++;

	if (*s == '-' || *s == '+')
		sign = (*s++ == '-' ? -1 : 1);

	while (_isdigit(*s))
		res = res * 10 + (*s++ - '0');

	return (sign * res);
}
