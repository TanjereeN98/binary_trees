#include "binary_trees.h"

/**
* bst_search - Searches for a value in a Binary Search Tree
* @tree: a pointer to the root node of the BST to search
* @value: the value to search in the tree
*
* Return:
*	A pointer to the node containing a value equals to value,
*	or NULL if tree is NULL.
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (value > tree->n)
		{
			if (!tree->right)
				break;

			tree = tree->right;
		}

		if (value < tree->n)
		{
			if (!tree->left)
				break;

			tree = tree->left;
		}
	}

	return (NULL);
}
