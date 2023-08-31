#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "11-binary_tree_size.c"
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
