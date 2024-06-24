#include "binary_trees.h"

/**
 * binary_tree_sibling - Get sibling of a node in a binary tree.
 * @node: Pointer to the node for which sibling is to be found.
 *
 * Return: NULL if node is NULL or has no sibling;
 * otherwise, the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
