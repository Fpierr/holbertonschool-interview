#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
void print_the_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: The sandpile grid
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * toppling - Topples the sandpile (redistributes grains)
 * @grid: The sandpile grid
 */
void toppling(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {0};

	/* Traverse the grid and distribute grains */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}
	/* Update the original grid */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First sandpile (result will be stored here)
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Stabilize the sandpile */
	while (!is_stable(grid1))
	{
		print_the_grid(grid1);
		toppling(grid1);
	}
}

