#include "binary_trees.h"

/**
 * binary_tree_size - measure size of binary tree
 *
 * @tree: pointer to root node of tree be measured
 *
 * Return: size of binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_node = 0;
	size_t right_node = 0;

	if (tree == NULL)
		return (0);

	left_node += binary_tree_size(tree->left);
	right_node += binary_tree_size(tree->right);

	return (left_node + right_node + 1);
}
