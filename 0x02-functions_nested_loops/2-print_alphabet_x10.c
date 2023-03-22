#include "main.h"

/**
 * print_alphabet_x10 - funtion to print a-z
 * description: prints a - z using a nested loop
 * Return: Always return 0
*/
void print_alphabet_x10(void)
{
	int h;
	int i;

	for (h = 1; h <= 10; h++)
	{
		for (i = 97; i <= 122; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
