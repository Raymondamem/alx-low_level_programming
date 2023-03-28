#include "main.h"

/**
* puts2 - printing function
* @str: parameter to print
* Return: void
*/
void puts2(char *str)
{
	int i = 0;
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}

	while (i < length)
	{
		_putchar(*(str + i));
		i += 2;
	}
	_putchar('\n');
}
