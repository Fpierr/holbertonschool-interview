#include "slide_line.h"
#include <sys/types.h>

/**
 * merge_left - Merges line values to the left like 2048
 * @line: Array of integers
 * @size: Size of the array
 */
void merge_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == 0)
			continue;
		for (j = i + 1; j < size; j++)
		{
			if (line[j] == 0)
				continue;
			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
			}
			break;
		}
	}
}

/**
 * merge_right - Merges line values to the right like 2048
 * @line: Array of integers
 * @size: Size of the array
 */
void merge_right(int *line, size_t size)
{
	ssize_t i, j;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
			continue;
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] == 0)
				continue;
			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
			}
			break;
		}
	}
}

/**
 * slide_left - Slides non-zero values to the left
 * @line: Array of integers
 * @size: Size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != pos)
			{
				line[pos] = line[i];
				line[i] = 0;
			}
			pos++;
		}
	}
}

/**
 * slide_right - Slides non-zero values to the right
 * @line: Array of integers
 * @size: Size of the array
 */
void slide_right(int *line, size_t size)
{
	ssize_t i, pos = size - 1;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != pos)
			{
				line[pos] = line[i];
				line[i] = 0;
			}
			pos--;
		}
	}
}

/**
 * slide_line - Executes a full slide & merge to one direction
 * @line: Array of integers
 * @size: Size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	else
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}

	return (1);
}

