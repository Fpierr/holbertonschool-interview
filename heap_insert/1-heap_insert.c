#include "binary_trees.h"

/**
 * heapify_up - Restores Max Heap property by swapping with parents
 * @node: Pointer to the node to heapify
 * Return: New position of node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * find_insert_parent - Finds the first parent with a free child
 * @root: Pointer to the root node
 * Return: Pointer to parent node for insertion
 */
heap_t *find_insert_parent(heap_t *root)
{
	heap_t **queue, *current;
	size_t front = 0, rear = 0, size = 1024;

	if (!root)
		return (NULL);

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];

		if (!current->left || !current->right)
			break;

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	free(queue);
	return (current);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node of the Heap
 * @value: Value to insert
 * Return: Pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insert_parent(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}

