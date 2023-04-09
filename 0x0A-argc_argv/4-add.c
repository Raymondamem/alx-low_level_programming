#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: agument count
 * @argv: agument vector
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i;
	int j;
	char *arg;

	for (i = 1; i < argc; i++)
	{
		arg = argv[i];
		for (j = 0; arg[j] != '\0'; j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
