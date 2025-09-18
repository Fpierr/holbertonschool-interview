#include "sort.h"

/**
 * merge - merge two sorted subarrays array
 * @size: size of the array
 * @array: pointer to the head of the array
 * @left: pointer to left array
 * @right: pointer to right array
 **/
void merge(size_t size, int *array, int *left, int *right)
{
	int i, j, k, l_lengh, r_lengh;

	i = j = k = 0;
	l_lengh = size / 2;
	r_lengh = size - l_lengh;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_lengh);
	printf("[right]: ");
	print_array(right, r_lengh);

	while (i < l_lengh && j < r_lengh)
		array[k++] = (left[i] < right[j]) ? left[i++] : right[j++];

	while (i < l_lengh)
		array[k++] = left[i++];

	while (j < r_lengh)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order using Merge Sort
 * @array: pointer to the head of the array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle, i;
	int left[SIZE_MAX], right[SIZE_MAX];

	if (!array || size < 2)
		return;

	for (i = 0, middle = size / 2; i < middle; i++)
		left[i] = array[i];

	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(size, array, left, right);
}
