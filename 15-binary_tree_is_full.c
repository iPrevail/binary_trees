#include "binary_trees.h"

/**
 * is_full_recursive - Recursively checks if a binary tree is perfect.
 * @tree: Ptr to the root node of the tree to check.
 *
 * Return: 0 if not perfect, 1 if perfect.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Determines if a binary tree is full.
 * @tree: Pointer to the root node for tree traversal.
 *
 * Return: 0 if tree is NULL or not full; else, returns 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
