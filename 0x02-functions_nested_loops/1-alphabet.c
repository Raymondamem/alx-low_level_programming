#include "main.h"

/**
 * print_alphabet - funtion to print a-z
 * Return: Always return 0
*/
void print_alphabet(void)
{
	int i = 97;

	for (i = 97; i <= 122; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
