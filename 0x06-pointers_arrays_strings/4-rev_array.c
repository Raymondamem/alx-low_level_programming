#include "main.h"
#include <stdlib.h>

/**
 * reverse_array - reverse the items for an array
 * @a: the array to reverse
 * @n: number of items in the array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int *newArr = (int *)malloc(sizeof(int) * n);
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++)
	{
		newArr[i] = a[i];
	}
	for (j = n - 1, i = 0; j > -1; i++, j--)
	{
		a[j] = newArr[i];
	}
	free(newArr);
}
