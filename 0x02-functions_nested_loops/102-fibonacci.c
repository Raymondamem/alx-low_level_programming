#include "main.h"

/**
 * print_number - prints number
 * @n: number to print
 * Return: void
 */
void print_number(unsigned long n)
{
	if (n >= 10)
		print_number(n / 10);
	_putchar(n % 10 + '0');
}

/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	unsigned long a = 1, b = 2;
	unsigned long temp;
	int i;

	print_number(a);
	_putchar(',');
	_putchar(' ');
	print_number(b);
	for (i = 0; i < 48; i++)
	{
		temp = b;
		b = a + b;
		a = temp;
		_putchar(',');
		_putchar(' ');
		print_number(b);
	}
	_putchar('\n');
	return (0);
}
