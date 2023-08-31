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
	int bf = 0;

	if (!tree)
		return (0);
	bf = binary_tree_height(tree->left) - binary_tree_height(tree->right);
	return (bf);
}
