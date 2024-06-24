#include "binary_trees.h"

/**
 * bst_search - Locate value in binary search tree.
 * @tree: Root node of the BST to explore.
 * @value: Value to find in the BST.
 *
 * Return: NULL if tree is empty or value not found;
 * else, node pointer.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
