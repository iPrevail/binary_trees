#include "binary_trees.h"

/**
 * binary_tree_delete - Removes a binary tree.
 * @tree: Pointer to the root node for tree deletion.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
