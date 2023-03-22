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
	int abs_value;
	int last_digit;
	
	if (n == INT_MIN)
		abs_value = INT_MAX + 1;
	else if(n < 0)
		abs_value = n * -1;
	else
		abs_value = n;
	last_digit = abs_value % 10;
	_putchar(last_digit + '0');

	return (last_digit);
}
