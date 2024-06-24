#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree in-order,
 * calling a function on each node.
 * @tree: Root node of the tree to traverse.
 * @func: Function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
