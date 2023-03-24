#include <stdio.h>
#include <math.h>

int _putchar(char c);

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n = 612852475143;
	long int maxPrime = -1;

	while (n % 2 == 0)
	{
		maxPrime = 2;
		n >>= 1;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			maxPrime = i;
			n = n / i;
		}
	}
	if (n > 2)
		maxPrime = n;

	/* print result using _putchar */
	int num = maxPrime;
	int rev = 0;

	while (num != 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	while (rev != 0)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
	}
	_putchar('\n');
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
