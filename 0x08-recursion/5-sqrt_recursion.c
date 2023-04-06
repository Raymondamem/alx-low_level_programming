/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number to find the square root of.
 *
 * Return: the natural square root of n, or -1 if n does not have a natural
 * square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (find_sqrt(n, 1, n));
}

/**
 * find_sqrt - finds the square root of a number recursively.
 * @n: the number to find the square root of.
 * @start: the starting point for the search.
 * @end: the ending point for the search.
 *
 * Return: the natural square root of n, or -1 if n does not have a natural
 * square root.
 */
int find_sqrt(int n, int start, int end)
{
	int mid = (start + end) / 2;

	if (mid * mid == n)
		return (mid);

	if (start >= end)
		return (-1);

	if (mid * mid > n)
		return (find_sqrt(n, start, mid - 1));
	else
		return (find_sqrt(n, mid + 1, end));
}
