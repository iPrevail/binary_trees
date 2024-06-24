#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a binary tree node.
 * @tree: Pointer to the node whose depth is to be determined.
 *
 * Return: 0 if tree is NULL, otherwise return the depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
