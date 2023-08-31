#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * _binary_tree_levelorder - Assists 'binary_tree_levelorder' func
 * @tree: _
 * @target_lvl: _
 * @lvl: _
 * @func: _
 */
void _binary_tree_levelorder(
	const binary_tree_t *tree,
	size_t target_lvl,
	size_t lvl,
	void (*func)(int)
)
{
	if (!tree)
		return;

	if (lvl == target_lvl)
		func(tree->n);

	_binary_tree_levelorder(tree->left, target_lvl, lvl + 1, func);
	_binary_tree_levelorder(tree->right, target_lvl, lvl + 1, func);
}

/**
* binary_tree_levelorder - traverse a binary tree using level-order traversal
* @tree: A pointer to the root node of the tree to traverse
* @func: A pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, target_lvl;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (target_lvl = 0; target_lvl <= height; target_lvl++)
		_binary_tree_levelorder(tree, target_lvl, 0, func);
}
