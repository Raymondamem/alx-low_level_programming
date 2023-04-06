#include "main.h"

/**
 * _sqrt_recursion_helper - prints a string in reverse
 * @n: the string to print
 * @i: the string to print
 * Return: int
 */
int _sqrt_recursion_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt_recursion_helper(n, i + 1));
}

/**
 * _sqrt_recursion - prints a string in reverse
 * @n: the string to print
 * Return: int
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_recursion_helper(n, 0));
}
