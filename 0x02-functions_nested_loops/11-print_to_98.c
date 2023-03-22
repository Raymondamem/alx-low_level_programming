#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	int tens, ones;

	if (n <= 98)
	{
		for (; n <= 98; n++)
		{
			if (n < 0)
			{
				_putchar('-');
				tens = -n / 10;
				ones = -n % 10;
				if (tens > 0)
					_putchar(tens + '0');
				_putchar(ones + '0');
			}
			else
			{
				tens = n / 10;
				ones = n % 10;
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
			tens = n / 10;
			ones = n % 10;
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
