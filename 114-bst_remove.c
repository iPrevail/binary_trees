#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Locates the smallest value in a binary search tree.
 * @root: Pointer to the root node of the BST.
 *
 * Result: The minimum value within the provided BST.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Annihilates a node in the binary search tree.
 * @root: Pointer to the root of the BST.
 * @node: Node to obliterate from the BST.
 *
 * Return: Returns the new root after devastation.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Recursively removes a value from the BST.
 * @root: Pointer to BST's root for deletion operation.
 * @node: Current node during removal process.
 * @value: Value to erase from the BST.
 *
 * Return: Updated root node after successful deletion.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Eliminates a node from a binary search tree.
 * @root: Root node pointer of the BST to erase a value from.
 * @value: Value to eradicate from the BST.
 *
 * Return: Pointer to the reborn root node post elimination.
 *
 * Description: Replaces a node with its in-order
 * successor if it has two children.
 *       Handles the extraction of a specific value from the BST gracefully.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
