#include "main.h"

/**
 * is_prime_number_helper - prints a string in reverse
 * @n: the string to print
 * @i: the string to print
 * Return: int
 */
int is_prime_number_helper(int n, int i)
{
	if (n <= 2)
		return ((n == 2) ? 1 : 0);
	if (n % i == 0)
		return (0);
	if (i * i > n)
		return (1);
	return (is_prime_number_helper(n, i + 1));
}

/**
 * is_prime_number - prints a string in reverse
 * @n: the string to print
 * Return: int
 */
int is_prime_number(int n)
{
	return (is_prime_number_helper(n, 2));
}
