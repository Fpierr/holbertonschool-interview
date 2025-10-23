#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (!tree)
		return (0);
	left_h = height(tree->left);
	right_h = height(tree->right);
	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Helper to check AVL property recursively
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int balance;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	balance = (int)height(tree->left) - (int)height(tree->right);
	if (balance > 1 || balance < -1)
		return (0);
	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

