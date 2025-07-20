#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new node with given value and parent
 * @parent: Pointer to the parent node
 * @value: The value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * array_to_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the subtree, or NULL on failure
 */
static avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;

	root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = array_to_avl(array, start, mid - 1, root);
	root->right = array_to_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (array_to_avl(array, 0, (int)size - 1, NULL));
}

