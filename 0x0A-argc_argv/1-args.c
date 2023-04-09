#include <stdio.h>

/**
 * main - Prints the number of arguments passed to the program.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the strings which are those arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	argv[0] = "d";
	printf("%d\n", argc - 1);
	return (0);
}
