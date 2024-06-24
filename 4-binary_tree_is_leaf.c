#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determine if a binary tree node is a leaf.
 * @node: Pointer to the node for examination.
 *
 * Return: 1 if it's a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
