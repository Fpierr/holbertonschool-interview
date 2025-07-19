#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Restores Max Heap property by swapping with parents
 * @node: Pointer to the node to heapify
 *
 * Return: New position of node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;
	int temp;

	if (!node)
		return (NULL);

	parent = node->parent;
	while (parent && node->n > parent->n)
	{
		temp = parent->n;
		parent->n = node->n;
		node->n = temp;
		node = parent;
		parent = node->parent;
	}

	return (node);
}

/**
 * find_insert_parent - Finds the first parent with a free child
 * @root: Pointer to the root node
 *
 * Return: Pointer to parent node for insertion
 */
heap_t *find_insert_parent(heap_t *root)
{
	heap_t *queue[1024];
	int head = 0, tail = 0;
	heap_t *current;

	if (!root)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		current = queue[head++];
		if (!current->left || !current->right)
			return (current);

		if (current->left)
			queue[tail++] = current->left;
		if (current->right)
			queue[tail++] = current->right;
	}

	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *insert_point;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insert_point = find_insert_parent(*root);
	if (!insert_point)
		return (NULL);

	new_node = binary_tree_node(insert_point, value);
	if (!new_node)
		return (NULL);

	if (!insert_point->left)
		insert_point->left = new_node;
	else
		insert_point->right = new_node;

	return (heapify_up(new_node));
}

