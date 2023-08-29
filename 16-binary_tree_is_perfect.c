#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is full
 * @tree: root node
 * Return: 1 is_perfect otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, i, power = 1;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	for (i = 0 ; i <= height ; i++)
		power *= 2;

	return (size == power - 1);
}

/**
* binary_tree_size - Measures the size of a binary tree
* @tree: A pointer to the root node of the tree to measure the size
*
* Return: The size of the binary tree, or 0 if tree is NULL.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
