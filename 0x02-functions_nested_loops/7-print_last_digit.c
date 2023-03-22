#include "main.h"
#include <limits.h>

/**
 * print_last_digit - gets the last digit of a number
 * @n: The number to get the last digit
 *
 * Return: the last digit of @n
 */
int print_last_digit(int n)
{
	int last_digit;

	if (n < 0)
		n = -1 * n;

	last_digit = n % 10;

	_putchar(last_digit + '0');

	return (last_digit);
}
