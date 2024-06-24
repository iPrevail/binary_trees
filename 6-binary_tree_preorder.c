#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree in pre-order.
 * @tree: Pointer to the root node for traversal.
 * @func: Pointer to a function for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
