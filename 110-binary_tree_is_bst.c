#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Validates if a binary tree is a BST.
 * @tree: Root node of the tree to check.
 * @lo: Smallest visited node value thus far.
 * @hi: Largest visited node value this far.
 *
 * Return: 1 if valid BST, else 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Validates if binary tree is a proper
 * binary search tree.
 * @tree: Pointer to the root node for verification.
 *
 * Return: 1 for valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
