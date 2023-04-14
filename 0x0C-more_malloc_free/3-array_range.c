#include "main.h"
#include <stdlib.h>

/**
 * array_range - creating an array
 * @min: number
 * @max: number
 * Return: int pointer
 */

#include <stdlib.h>

int *array_range(int min, int max)
{
	int *arr;
	int i;

	if (min > max)
		return (NULL);

	arr = malloc(sizeof(int) * (max - min + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; min <= max; i++, min++)
		arr[i] = min;

	return (arr);
}
