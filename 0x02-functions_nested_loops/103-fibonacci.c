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
	unsigned long sum = 0;
	unsigned long temp;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
			sum += b;
		temp = b;
		b = a + b;
		a = temp;
	}
	print_number(sum);
	_putchar('\n');
	return (0);
}
