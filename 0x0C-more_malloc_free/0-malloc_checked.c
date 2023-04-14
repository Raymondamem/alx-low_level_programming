#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - creating memory on the heap
 * @b: size of memory o create
 * Return: void
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}

	return (ptr);
}
