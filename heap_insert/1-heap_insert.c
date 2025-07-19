#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree or 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_by_index - Gets the node at a given index using level-order
 * @tree: Root node
 * @index: Index of the node to find
 * Return: Pointer to the node at index
 */
binary_tree_t *get_node_by_index(binary_tree_t *tree, size_t index)
{
	size_t mask = 1UL << (sizeof(size_t) * 8 - 1);

	if (!tree || index == 0)
		return ((binary_tree_t *)tree);

	while ((mask & index) == 0)
		mask >>= 1;
	mask >>= 1;

	while (mask > 0 && tree)
	{
		if (index & mask)
			tree = tree->right;
		else
			tree = tree->left;
		mask >>= 1;
	}

	return ((binary_tree_t *)tree);
}

/**
 * heapify_up - Moves a node up to maintain Max Heap order
 * @node: Pointer to the node to heapify
 * Return: Pointer to the new position of the node
 */
heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the new node
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = get_node_by_index(*root, (size - 1) / 2);
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

