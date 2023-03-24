#include "main.h"

/**
 * print_string - prints a string
 * @string: string to print
 * Return: void
 */
void print_string(char string[])
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}

/**
 * print_number - prints any number
 * @number: the number to print
 * Return: void
 */
void print_number(int number)
{
	if (number / 10 != 0)
		print_number(number / 10);

	_putchar(number % 10 + '0');
}

/**
 * main - entry point
 * Return: Always 0 on success
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3 == 0) && (i % 5) == 0)
		{
			print_string("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			print_string("Fizz");
		}
		else if (i % 5 == 0)
		{
			print_string("Buzz");
		}
		else
		{
			print_number(i);
		}
		if (i != 100)
		{
			_putchar(' ');
		}
	}
	_putchar('\n');
	return (0);
}
