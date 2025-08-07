#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary_recursive - Recursive binary search.
 * @array: Pointer to subarray to search.
 * @left: Left index.
 * @right: Right index.
 * @value: Value to find.
 *
 * Return: Index of value or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - Advanced binary search wrapper.
 * @array: Pointer to array.
 * @size: Number of elements.
 * @value: Value to find.
 *
 * Return: Index of value or -1 if not found or array NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

