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
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @f: A pointer to the first node
* @s: A pointer to the second node
*
* Return:
*	The lowest common ancestor node of the two given nodes,
*	or NULL if  no common ancestor was found.
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *f,
	const binary_tree_t *s
)
{
	size_t first_depth, second_depth, close_depth, far_depth, i;
	const binary_tree_t **far;

	if (!f || !s)
		return (NULL);

	first_depth = depth(f);
	second_depth = depth(s);
	far_depth = first_depth > second_depth ? first_depth : second_depth;
	close_depth = first_depth > second_depth ? second_depth : first_depth;
	far = first_depth > second_depth ? &f : &s;

	for (i = far_depth; i > close_depth; i--)
		*far = (*far)->parent;

	while (f != s)
	{
		if (!f->parent || !s->parent)
			return (NULL);
		f = f->parent;
		s = s->parent;
	}

	return ((binary_tree_t *) f);
}
