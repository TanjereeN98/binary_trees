#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	tmp = *tree;

	while (true)
	{
		if (value == tmp->n)
			return (NULL);

		if (value > tmp->n)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}

			tmp->right = binary_tree_node(tmp, value);
			return (tmp->right);
		}

		if (value < tmp->n)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}

			tmp->left = binary_tree_node(tmp, value);
			return (tmp->left);
		}
	}
}
