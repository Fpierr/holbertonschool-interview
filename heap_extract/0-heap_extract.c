#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - counts the number of nodes in a binary tree
 * @tree: pointer to the root node
 * Return: number of nodes
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * node_at_index - finds the node of a heap at a given index
 * @root: pointer to the heap root
 * @idx: index (root = 1)
 * Return: pointer to the node, or NULL
 */
static heap_t *node_at_index(heap_t *root, size_t idx)
{
	size_t tmp = idx, depth = 0, mask;
	heap_t *node = root;

	if (!root || idx == 0)
		return (NULL);

	while (tmp >>= 1)
		depth++;

	mask = 1UL << (depth - 1);
	while (mask && node)
	{
		if (idx & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}
	return (node);
}

/**
 * heapify_down - restores the max-heap property by sifting down
 * @node: starting node
 */
static void heapify_down(heap_t *node)
{
	heap_t *largest;
	int tmp;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;

		node = largest;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root of the heap
 * Return: value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	size_t size;
	int value;
	heap_t *last, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	size = binary_tree_size(*root);
	last = node_at_index(*root, size);

	(*root)->n = last->n;

	parent = last->parent;
	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(last);

	heapify_down(*root);

	return (value);
}
