#include "binary_trees.h"

/**
 * create_tree - recursively constructs AVL tree nodes
 *
 * @node: pointer to current node
 * @array: array of integers
 * @size: size of array
 * @mode: 1 for left, 2 for right addition
 * Return: void
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - Assembles AVL tree from sorted int array
 *
 * @array: Input array of integers
 * @size: Size of the array
 * Return: Pointer to the AVL root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}