#include "binary_trees.h"
#include "113-bst_search.c"

/**
 * in_order_successor - Finds first in-order successor
 * @tree: A pointer to the tree to get its first in-order successor
 *
 * Return: A pointer to first in-order successor, or NULL if tree is NULL.
 */
bst_t *in_order_successor(bst_t *tree)
{
	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree->left ? tree->left : tree);

	tree = tree->right;

	while (tree->left)
		tree = tree->left;

	return (tree);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return:
 *	A pointer to the new root node of the tree after removing the value,
 *	or NULL if root is NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *r, *s;

	if (!root)
		return (NULL);

	r = bst_search(root, value);
	s = in_order_successor(r);

	if (s->n < s->parent->n)
		s->parent->left = NULL;

	if (s->n > s->parent->n)
		s->parent->right = NULL;

	r->n = s->n;

	free(s);

	return (root);
}
