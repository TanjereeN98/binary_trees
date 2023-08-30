#include "binary_trees.h"

/**
 * depth - Measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of the node, or 0 if tree id NULL.
 */
size_t depth(const binary_tree_t *tree)
{
	if (!tree || !(tree->parent))
		return (0);

	return (depth(tree->parent) + 1);
}

/**
 * height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * traverse_level - Traverse a binary tree level
 * @tree: A pointer to the root node of the tree to traverse
 * @level: The level to be traversed
 * @func: A pointer to a function to call for each node in the level
 */
void traverse_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (depth(tree) == level)
		func(tree->n);

	traverse_level(tree->left, level, func);
	traverse_level(tree->right, level, func);
}

/**
* binary_tree_levelorder - goes through a binary tree using level-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, l;

	if (!tree || !func)
		return;

	h = height(tree);

	for (l = 0; l <= h; l++)
		traverse_level(tree, l, func);
}
