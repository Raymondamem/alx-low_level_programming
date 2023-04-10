#include "main.h"

/**
 * _puts - prints a string
 * @s: the string to print
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}
