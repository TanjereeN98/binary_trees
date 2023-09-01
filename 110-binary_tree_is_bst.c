#include "binary_trees.h"

/**
 * bst_min - Finds min value in BST
 * @tree: A pointer to the root node of the tree
 *
 * Return: the min value in thr tree
 */
int bst_min(bst_t *tree)
{
	while (tree->left)
		tree = tree->left;

	return (tree->n);
}

/**
 * bst_max - Finds max value in BST
 * @tree: A pointer to the root node of the tree
 *
 * Return: the max value in thr tree
 */
int bst_max(bst_t *tree)
{
	while (tree->right)
		tree = tree->right;

	return (tree->n);
}

/**
 * _binary_tree_is_bst - Assists 'binary_tree_is_bst' function
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, or 0 otherwise.
 */
int _binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left)
	{
		if (bst_max(tree->left) >= tree->n)
			return (0);
	}

	if (tree->right)
	{
		if (bst_min(tree->right) <= tree->n)
			return (0);
	}

	return (_binary_tree_is_bst(tree->left) & _binary_tree_is_bst(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return:
 *	1 if tree is a valid BST, 0 otherwise,
 *	or 0 If tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_is_bst(tree));
}
