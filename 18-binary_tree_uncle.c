#include "binary_trees.h"

/**
 * binary_tree_uncle - Seek the uncle node in a binary tree.
 * @node: Target node for uncle identification.
 *
 * Return: NULL if node is NULL or lacks an uncle;
 * otherwise, uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
