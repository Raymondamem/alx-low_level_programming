#include <stdio.h>

/**
 * main - entry function
 * description: Prints 0 - 9
 * Return: Alway 0
 */
int main(void)
{
	int number = 48;
	int number2 = 49;

	while (number <= 56)
	{
		while (number2 <= 57)
		{
			putchar(number);
			putchar(number2);
			if (number < 56)
			{
				putchar(',');
				putchar(' ');
			}
			number2++;
		}
		number++;
		number2 = number + 1;
	}
	putchar('\n');
	return (0);
}
