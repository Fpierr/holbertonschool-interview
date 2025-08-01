#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - Maintains max-heap property for subtree rooted at index i
 * @array: Array of integers
 * @size: Size of the array
 * @i: Index of the root of the subtree
 * @heap_size: Current size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t heap_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_ints(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array of integers using Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}

