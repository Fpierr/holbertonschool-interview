#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_blank - Checks if position (x, y) should be a blank
 * @x: column
 * @y: row
 * Return: 1 if blank, 0 otherwise
 */
int is_blank(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge of given level
 * @level: level of the sponge
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_blank(col, row))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

