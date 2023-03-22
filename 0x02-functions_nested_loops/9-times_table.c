#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row, col, prod;

	for (row = 0; row <= 9; row++)
	{
	_putchar('0');
	_putchar(',');
	_putchar(' ');

	for (col = 1; col <= 9; col++)
	{
		prod = row * col;

	if (prod <= 9)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(prod + '0');
	}
	else
	{
	_putchar(' ');
	_putchar((prod / 10) + '0');
	_putchar((prod % 10) + '0');
	}

	if (col < 9)
	{
	_putchar(',');
	_putchar(' ');
	}
	}
	_putchar('\n');
	}
}
