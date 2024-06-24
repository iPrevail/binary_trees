#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts internal nodes in a binary tree.
 * @tree: Pointer to the root node; counts nodes with at least 1 child.
 *
 * Return: If tree is NULL, return 0; otherwise, return internal node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
