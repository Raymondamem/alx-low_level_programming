#include "main.h"

/**
 * print_line - prints line on the terminal
 * @n: number of _ to print on the terminal
 * Return: void
 */
void print_line(int n)
{
	int i;

	for (i = n; i > 0; i--)
		_putchar('_');

	_putchar('\n');
}
