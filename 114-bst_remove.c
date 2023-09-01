#include "binary_trees.h"
#include "113-bst_search.c"

/**
 * successor - _
 * @tree: _
 *
 * Return: _
 */
bst_t *successor(bst_t *tree)
{
	if (!tree)
		return (NULL);

	if (!tree->left && !tree->right)
		return (tree);

	if (!tree->right)
		return (tree->left);

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
	bst_t *t, *s;

	t = bst_search(root, value);

	if (!t)
		return (NULL);

	s = successor(t);

	if (s->n < s->parent->n)
		s->parent->left = s->left;

	if (s->n > s->parent->n)
		s->parent->right = s->right;

	if (t != s)
	{
		root = t->parent ? root : s;
		s->parent = t->parent;

		if (t->parent && t->n < t->parent->n)
			t->parent->left = s;

		if (t->parent && t->n > t->parent->n)
			t->parent->right = s;

		if (t->left)
			t->left->parent = s;

		s->left = t->left;

		if (t->right)
			t->right->parent = s;

		s->right = t->right;
	}

	free(t);

	return (root);
}
