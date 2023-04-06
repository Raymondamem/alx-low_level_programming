/**
 * _pow_recursion - calculates the value of x raised to the power of y
 * @x: the base integer
 * @y: the exponent integer
 *
 * Return: the result of the exponentiation, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
