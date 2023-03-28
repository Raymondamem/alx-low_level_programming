#include "main.h"

/**
 * puts_half - puts more char
 * @str: string to puts
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int n = 0;
	int i = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}
	n = length / 2;
	if (length % 2 != 0)
	{
		n = (length - 1) / 2;
		n++;
	}
	for (i = n; i < length; i++)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}
