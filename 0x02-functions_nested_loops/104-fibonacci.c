int _putchar(char c);

void long_to_str(long n, char *buffer);

void print_long(long n1, long n2);

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long a1 = 0;
	long a2 = 1;
	long b1 = 0;
	long b2 = 2;
	long c1;
	long c2;

	/* Print first two Fibonacci numbers */
	print_long(a1, a2);
	_putchar(',');
	_putchar(' ');
	print_long(b1, b2);

	/* Print remaining Fibonacci numbers */
	for (int i = 3; i <= 98; i++)
	{
	c1 = a1 + b1;
	c2 = a2 + b2;
	if (c2 > 999999999)
	{
		c1 += c2 / 1000000000;
		c2 %= 1000000000;
	}
	_putchar(',');
	_putchar(' ');
	print_long(c1, c2);
	a1 = b1;
	a2 = b2;
	b1 = c1;
	b2 = c2;
	}
	_putchar('\n');

	return (0);
}

/**
 * print_long - prints a long represented as two long variables
 * @n1: the upper digits of the long
 * @n2: the lower 9 digits of the long
 */
void print_long(long n1, long n2)
{
	char buffer[12];

	if (n1 > 0)
	{
	long_to_str(n1, buffer);
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		_putchar(buffer[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		_putchar((n2 / 100000000) + '0');
		n2 %= 100000000;
		n2 *= 10;
	}
	}
	else
	{
	long_to_str(n2, buffer);
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		_putchar(buffer[i]);
	}
	}
}

/**
 * long_to_str - converts a long to a string of characters
 * @n: the long to convert
 * @buffer: the buffer to store the resulting string
 */
void long_to_str(long n, char *buffer)
{
	int length = 0;
	long temp = n;

	/* Compute length of string */
	do {
	length++;
	temp /= 10;
	} while (temp > 0);

	/* Store digits as characters in buffer */
	or (int i = length - 1; i >= 0; i--)
	{
	buffer[i] = (n % 10) + '0';
	n /= 10;
	}
	buffer[length] = '\0';
}
