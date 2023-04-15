#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Free 2D array
 * @grid: 2D array
 * @height: Number of rows
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
