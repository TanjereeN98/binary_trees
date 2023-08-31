#include "binary_trees.h"
#include "10-binary_tree_depth.c"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: A pointer to the first node
* @second: A pointer to the second node
*
* Return:
*	The lowest common ancestor node of the two given nodes,
*	or NULL if  no common ancestor was found.
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second
)
{
	size_t first_depth, second_depth, close_depth, far_depth, i;
	const binary_tree_t **far;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	far_depth = first_depth > second_depth ? first_depth : second_depth;
	close_depth = first_depth > second_depth ? second_depth : first_depth;
	far = first_depth > second_depth ? &first : &second;

	for (i = far_depth; i > close_depth; i--)
		*far = (*far)->parent;

	while (first != second)
	{
		if (!first->parent || !second->parent)
			return (NULL);
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *) first);
}
