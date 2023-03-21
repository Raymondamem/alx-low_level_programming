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
	int number3 = 50;

	while (number <= 55)
	{
		while (number2 <= 56)
		{
			while (number3 <= 57)
			{
				putchar(number);
				putchar(number2);
				putchar(number3);
				if (number < 55)
				{
					putchar(',');
					putchar(' ');
				}
				number3++;
			}
			number2++;
			number3 = number2 + 1;
		}
		number++;
		number2 = number;
	}
	putchar('\n');
	return (0);
}
