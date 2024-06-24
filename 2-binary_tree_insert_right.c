#include "binary_trees.h"

/**
 * binary_tree_insert_right - Add a node as the right-child in a binary tree.
 * @parent: Node to insert the right-child under.
 * @value: Value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Else - a pointer to the new right-child node.
 *
 * Description: If parent has a right-child, new node replaces it, and the old
 *              right-child becomes the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
