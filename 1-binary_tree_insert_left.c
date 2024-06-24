#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node as a left
 * child in a binary tree.
 * @parent: Node to receive the new left child.
 * @value: Value to store in the new left child node.
 *
 * Return: NULL on failure or if parent is NULL;
 * otherwise, the new node.
 *
 * Description: If parent already has a left child,
 * the new node takes its
 *              place, and the old left child becomes the left
 *              child of the
 *              new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
