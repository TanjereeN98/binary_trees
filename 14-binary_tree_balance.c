#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;

	if (!tree)
		return (0);
	balance_factor = tree_height(tree->left) - tree_height(tree->right);
	return (balance_factor);
}
