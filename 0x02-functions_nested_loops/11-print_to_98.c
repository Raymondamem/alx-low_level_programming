#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
	for (; n <= 98; n++)
	{
		if (n < 0)
		{
			_putchar('-');
			int tens = -n / 10;
			int ones = -n % 10;
			if (tens > 0)
				_putchar(tens + '0');
			_putchar(ones + '0');
		}
		else
		{
			int tens = n / 10;
			int ones = n % 10;
			if (tens > 0)
				_putchar(tens + '0');
			_putchar(ones + '0');
		}
		if (n != 98)
		{
			_putchar(',');
			_putchar(' ');
		}
	}
	}
	else
	{
		for (; n >= 98; n--)
		{
			int tens = n / 10;
			int ones = n % 10;
			if (tens > 0)
				_putchar(tens + '0');
			_putchar(ones + '0');
			if (n != 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
	_putchar('\n');
}
