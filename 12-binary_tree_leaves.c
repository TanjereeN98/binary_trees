#include "binary_trees.h"

/**
* binary_tree_leaves - Counts the leaves in a binary tree
* @tree: A pointer to the root node of the tree to count the number of leaves
*
* Return: The count of the leaves, or 0 if tree is NULL.
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right) && tree->parent)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
