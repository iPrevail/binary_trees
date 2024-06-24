#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Validates if a binary tree node is a leaf.
 * @node: Ptr to the node for validation.
 *
 * Return: 1 if leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Gauges depth of a node in binary tree.
 * @tree: Node to assess depth.
 *
 * Return: Depth of the provided node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Explores a binary tree to locate its terminal node.
 * @tree: The root of the binary tree to traverse
 * in search of a terminal node.
 *
 * Return: A pointer to the first discovered terminal leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Validates binary tree perfection recursively.
 * @tree: Ptr to the root node of the tree for validation.
 * @leaf_depth: Depth of a leaf in the binary tree.
 * @level: Current node's level during recursive traversal.
 *
 * Return: 1 if the tree is perfect, else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Validates if a binary tree is perfect.
 * @tree: Root node pointer of the tree to be examined.
 *
 * Return: Returns 1 for a perfect tree, 0 otherwise or if root is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
