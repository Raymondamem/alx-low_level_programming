#include <stdio.h>
#include <stdlib.h>

void print_opcodes(void (*func)(void), int num_bytes);

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 if wrong number of arguments, 2 if negative num_bytes
 */
int main(int argc, char **argv)
{
	int num_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes(main, num_bytes);

	return (0);
}

/**
 * print_opcodes - prints the opcodes of a function
 * @func: pointer to the function to print opcodes of
 * @num_bytes: number of bytes to print
 */
void print_opcodes(void (*func)(void), int num_bytes)
{
	int i;
	unsigned char *opcodes = (unsigned char *)func;

	for (i = 0; i < num_bytes; i++)
		printf("%.2x ", opcodes[i]);

	printf("\n");
}
