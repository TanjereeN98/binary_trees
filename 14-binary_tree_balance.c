#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree)
		return (0);

	lh = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	rh = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((int) lh - (int) rh);
}
