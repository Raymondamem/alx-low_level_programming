#include "main.h"

/**
 * print_number - prints number
 * @n: number to print
 * Return: void
 */
void print_number(int n)
{
	int i = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (n / i > 9)
	{
		i *= 10;
	}
	while (i > 0)
	{
		_putchar(n / i + '0');
		n %= i;
		i /= 10;
	}
}

/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	int i;
	int sum = 0;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		sum += i;
	}
	print_number(sum);
	_putchar('\n');
	return (0);
}
