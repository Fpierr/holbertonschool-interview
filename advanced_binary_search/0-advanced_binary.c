#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the elements of an array
 * @array: pointer to the array
 * @left: left index
 * @right: right index
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Recursive binary search to find first occurrence
 * @array: pointer to array
 * @left: start index
 * @right: end index
 * @value: value to search
 * Return: index of first occurrence, or -1
 */
int binary_search_recursive(int *array, int left, int right, int value)
{
	int mid;
	int i;

	if (right < left)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (binary_search_recursive(array, left, mid, value));

	return (binary_search_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - wrapper function for binary_search_recursive
 * @array: sorted array
 * @size: number of elements
 * @value: value to search
 * Return: index of first occurrence or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, (int)size - 1, value));
}

